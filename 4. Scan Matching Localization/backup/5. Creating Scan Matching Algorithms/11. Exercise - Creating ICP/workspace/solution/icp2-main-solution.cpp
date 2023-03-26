// Udacity C3 Localization
// Dec 21 2020
// Aaron Brown

using namespace std;

#include <string>
#include <sstream>
#include "helper.h"

#include <Eigen/Core>
#include <Eigen/SVD>
using namespace Eigen;
#include <pcl/registration/icp.h>
#include <pcl/console/time.h>   // TicToc

Pose pose(Point(0,0,0), Rotate(0,0,0));
Pose upose = pose;
vector<int> associations;
vector<int> bestAssociations = {5,6,7,8,9,10,11,12,13,14,15,16,16,17,18,19,20,21,22,23,24,25,26,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,62,63,64,65,66,67,68,69,70,71,72,74,75,76,77,78,79,80,81,82,83,84,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,122,123,124,125,126,127,0,1,2,3,4,4};
bool init = false;
bool matching = false;
bool update = false;
void keyboardEventOccurred(const pcl::visualization::KeyboardEvent &event, void* viewer)
{

  	//boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer = *static_cast<boost::shared_ptr<pcl::visualization::PCLVisualizer> *>(viewer_void);
	if (event.getKeySym() == "Right" && event.keyDown()){
		update = true;
		upose.position.x += 0.1;
  	}
	else if (event.getKeySym() == "Left" && event.keyDown()){
		update = true;
		upose.position.x -= 0.1;
  	}
  	if (event.getKeySym() == "Up" && event.keyDown()){
		update = true;
		upose.position.y += 0.1;
  	}
	else if (event.getKeySym() == "Down" && event.keyDown()){
		update = true;
		upose.position.y -= 0.1;
  	}
	else if (event.getKeySym() == "k" && event.keyDown()){
		update = true;
		upose.rotation.yaw += 0.1;
		while( upose.rotation.yaw > 2*pi)
			upose.rotation.yaw -= 2*pi;  
  	}
	else if (event.getKeySym() == "l" && event.keyDown()){
		update = true;
		upose.rotation.yaw -= 0.1;
		while( upose.rotation.yaw < 0)
			upose.rotation.yaw += 2*pi; 
  	}
	else if (event.getKeySym() == "space" && event.keyDown()){
		matching = true;
		update = false;
  	}
	else if (event.getKeySym() == "n" && event.keyDown()){
		pose = upose;
		cout << "Set New Pose" << endl;
  	}
	else if (event.getKeySym() == "b" && event.keyDown()){
		cout << "Do ICP With Best Associations" << endl;
		matching = true;
		update = true;
  	}
}

double Score(vector<int> pairs, PointCloudT::Ptr target, PointCloudT::Ptr source, Eigen::Matrix4d transform){
	double score = 0;
	int index = 0;
	for(int i : pairs){
		Eigen::MatrixXd p(4, 1);
		p(0,0) = (*source)[index].x;
		p(1,0) = (*source)[index].y;
		p(2,0) = 0.0;
		p(3,0) = 1.0;
		Eigen::MatrixXd p2 = transform * p;
		PointT association = (*target)[i];
		score += sqrt( (p2(0,0) - association.x) * (p2(0,0) - association.x) + (p2(1,0) - association.y) * (p2(1,0) - association.y) );
		index++;
	}
	return score;
}
vector<Pair> estimations;

vector<int> NN(PointCloudT::Ptr target, PointCloudT::Ptr source, Eigen::Matrix4d initTransform, double dist){
	
	PointCloudT::Ptr transformSource (new PointCloudT); 
  	pcl::transformPointCloud (*source, *transformSource, initTransform);

	pcl::KdTreeFLANN<PointT> kdtree;
	kdtree.setInputCloud (target);

	vector<int> associations;

	int index = 0;
	for(PointT point : transformSource->points ){

		vector<int> pointIdxRadiusSearch;
  		vector<float> pointRadiusSquaredDistance;
		if ( kdtree.radiusSearch (point, dist, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0 )
 		{
			associations.push_back(pointIdxRadiusSearch[0]);
		}
		else{
			associations.push_back(-1);
		}
		index++;
	}

	return associations;
}

vector<Pair> PairPoints(vector<int> associations, PointCloudT::Ptr target, PointCloudT::Ptr source, bool render, pcl::visualization::PCLVisualizer::Ptr& viewer){

	vector<Pair> pairs;

	int index = 0;
	for(PointT point : source->points ){
		int i = associations[index];
		if( i >= 0)
		{
			PointT association = (*target)[i];
			if( render){
				viewer->removeShape(to_string(index));
				renderRay(viewer, Point(point.x, point.y,0), Point(association.x, association.y,0), to_string(index), Color(0,1,0));
			}
			pairs.push_back(Pair(Point(point.x, point.y,0), Point(association.x, association.y,0)) );
		}
		index++;
	}
	return pairs;
}

Eigen::Matrix4d ICP(vector<int> associations, PointCloudT::Ptr target, PointCloudT::Ptr source, Pose startingPose, int iterations, pcl::visualization::PCLVisualizer::Ptr& viewer){

  	// align source with starting pose
  	Eigen::Matrix4d initTransform = transform3D(startingPose.rotation.yaw, startingPose.rotation.pitch, startingPose.rotation.roll, startingPose.position.x, startingPose.position.y, startingPose.position.z);
  	PointCloudT::Ptr transformSource (new PointCloudT); 
  	pcl::transformPointCloud (*source, *transformSource, initTransform);

	vector<Pair> pairs = PairPoints(associations, target, transformSource, true, viewer);

	//cout << "score is " << Score(pairs, Eigen::MatrixXd::Identity(4,4) ) << endl;

	Eigen::MatrixXd X(2,pairs.size());
	Eigen::MatrixXd Y(2,pairs.size());
	Eigen::MatrixXd P(2,1);
	P << Eigen::MatrixXd::Zero(2,1);
	Eigen::MatrixXd Q(2,1);
	Q << Eigen::MatrixXd::Zero(2,1);

	for(Pair pair : pairs){
		P(0,0) += pair.p1.x;
		P(1,0) += pair.p1.y;

		Q(0,0) += pair.p2.x;
		Q(1,0) += pair.p2.y;
	}
	P(0,0) = P(0,0)/pairs.size();
	P(1,0) = P(1,0)/pairs.size();

	Q(0,0) = Q(0,0)/pairs.size();
	Q(1,0) = Q(1,0)/pairs.size();
	int index = 0;
	for(Pair pair : pairs){
		X(0,index) = pair.p1.x - P(0,0);
		X(1,index) = pair.p1.y - P(1,0);

		Y(0,index) = pair.p2.x - Q(0,0);
		Y(1,index) = pair.p2.y - Q(1,0);
		index++;
	}

	// compute best R and t from using SVD
	Eigen::MatrixXd S  = X * Y.transpose();
	JacobiSVD<MatrixXd> svd(S, ComputeFullV | ComputeFullU);
	Eigen::MatrixXd D;
	D.setIdentity(svd.matrixV().cols(), svd.matrixV().cols());
	D(svd.matrixV().cols()-1,svd.matrixV().cols()-1) = (svd.matrixV() * svd.matrixU().transpose() ).determinant();

	Eigen::MatrixXd R  = svd.matrixV() * D * svd.matrixU().transpose();
	Eigen::MatrixXd t  = Q - R * P;

	Eigen::Matrix4d transformation_matrix;
	transformation_matrix << Eigen::MatrixXd::Identity(4,4);

	transformation_matrix(0,0) = R(0,0);
	transformation_matrix(0,1) = R(0,1);
	transformation_matrix(1,0) = R(1,0);
	transformation_matrix(1,1) = R(1,1);
	transformation_matrix(0,3) = t(0,0);
	transformation_matrix(1,3) = t(1,0);

	//cout << "score is " << Score(pairs, transformation_matrix ) << endl;

	//cout << transformation_matrix << endl;

	estimations = pairs;
	transformation_matrix =  transformation_matrix * initTransform;
  	return transformation_matrix;

}

int main(){

	pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("ICP Creation"));
  	viewer->setBackgroundColor (0, 0, 0);
  	viewer->addCoordinateSystem (1.0);
	viewer->registerKeyboardCallback(keyboardEventOccurred, (void*)&viewer);

	// Load target
	PointCloudT::Ptr target(new PointCloudT);
  	pcl::io::loadPCDFile("target.pcd", *target);

	// Load source
	PointCloudT::Ptr source(new PointCloudT);
  	pcl::io::loadPCDFile("source.pcd", *source);

	renderPointCloud(viewer, target, "target", Color(0,0,1));
	renderPointCloud(viewer, source, "source", Color(1,0,0));
	viewer->addText("Score", 200, 200, 32, 1.0, 1.0, 1.0, "score",0);

  	while (!viewer->wasStopped ())
  	{
		if(matching){

			init = true;
			
			viewer->removePointCloud("usource");

			Eigen::Matrix4d transformInit = transform3D(pose.rotation.yaw, pose.rotation.pitch, pose.rotation.roll, pose.position.x, pose.position.y, pose.position.z);
			PointCloudT::Ptr transformed_scan (new PointCloudT);
  			pcl::transformPointCloud (*source, *transformed_scan, transformInit);
			viewer->removePointCloud("source");
  			renderPointCloud(viewer, transformed_scan, "source", Color(1,0,0));

			if(!update)
				associations = NN(target, source, transformInit, 5);
			else
				associations = bestAssociations;

			Eigen::Matrix4d transform = ICP(associations, target, source, pose, 1, viewer);

			pose = getPose(transform);
  			pcl::transformPointCloud (*source, *transformed_scan, transform);
			viewer->removePointCloud("icp_scan");
  			renderPointCloud(viewer, transformed_scan, "icp_scan", Color(0,1,0));

			double score = Score(associations,  target, source, transformInit);
			viewer->removeShape("score");
			viewer->addText("Score: "+to_string(score), 200, 200, 32, 1.0, 1.0, 1.0, "score",0);
			double icpScore = Score(associations,  target, source, transform);
			viewer->removeShape("iscore");
			viewer->addText("ICP Score: "+to_string(icpScore), 200, 150, 32, 1.0, 1.0, 1.0, "iscore",0);

			matching = false;
			update = false;
			upose = pose;
			
		}
		else if(update && init){

			Eigen::Matrix4d userTransform = transform3D(upose.rotation.yaw, upose.rotation.pitch, upose.rotation.roll, upose.position.x, upose.position.y, upose.position.z);

			PointCloudT::Ptr transformed_scan (new PointCloudT);
  			pcl::transformPointCloud (*source, *transformed_scan, userTransform);
			viewer->removePointCloud("usource");
			renderPointCloud(viewer, transformed_scan, "usource", Color(0,1,1));

			vector<Pair> pairs = PairPoints(associations, target, transformed_scan, true, viewer);

			double score = Score(associations,  target, source, userTransform);
			viewer->removeShape("score");
			viewer->addText("Score: "+to_string(score), 200, 200, 32, 1.0, 1.0, 1.0, "score",0);
			
			update = false;
			
		}

  		viewer->spinOnce ();
  	}
  	
	return 0;
}
