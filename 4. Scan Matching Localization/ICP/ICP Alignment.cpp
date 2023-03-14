Eigen::Matrix4d ICP(PointCloudT::Ptr target, PointCloudT::Ptr source, Pose startingPose, int iterations){

	// Defining a rotation matrix and translation vector
  	Eigen::Matrix4d transformation_matrix = Eigen::Matrix4d::Identity ();

  	// align source with starting pose
  	Eigen::Matrix4d initTransform = transform3D(startingPose.rotation.yaw, startingPose.rotation.pitch, startingPose.rotation.roll, startingPose.position.x, startingPose.position.y, startingPose.position.z);
  	PointCloudT::Ptr transformSource (new PointCloudT); 
  	pcl::transformPointCloud (*source,* transformSource, initTransform);

  	/*
  	if( count == 0)
  		renderPointCloud(viewer, transformSource, "transform_scan_"+to_string(count), Color(1,0,1)); // render corrected scan
  	*/
	
	pcl::console::TicToc time;
  	time.tic ();
  	pcl::IterativeClosestPoint<PointT, PointT> icp;
  	icp.setMaximumIterations (iterations);
  	icp.setInputSource (transformSource);
  	icp.setInputTarget (target);
	icp.setMaxCorrespondenceDistance (2);
	//icp.setTransformationEpsilon(0.001);
	//icp.setEuclideanFitnessEpsilon(.05);
	//icp.setRANSACOutlierRejectionThreshold (10);

  	PointCloudT::Ptr cloud_icp (new PointCloudT);  // ICP output point cloud
  	icp.align (*cloud_icp);
  	//std::cout << "Applied " << iterations << " ICP iteration(s) in " << time.toc () << " ms" << std::endl;

  	if (icp.hasConverged ())
  	{
  		//std::cout << "\nICP has converged, score is " << icp.getFitnessScore () << std::endl;
  		transformation_matrix = icp.getFinalTransformation ().cast<double>();
  		transformation_matrix =  transformation_matrix * initTransform;
  		//print4x4Matrix(transformation_matrix);


  		/*
  		PointCloudT::Ptr corrected_scan (new PointCloudT);
  		pcl::transformPointCloud (*source,* corrected_scan, transformation_matrix);
  		if( count == 1)
  			renderPointCloud(viewer, corrected_scan, "corrected_scan_"+to_string(count), Color(0,1,1)); // render corrected scan
		*/
  		return transformation_matrix;
  	}
	else
  		cout << "WARNING: ICP did not converge" << endl;
  	return transformation_matrix;

}

// cloudFiltered = scanCloud; // Make sure you removed this line
pcl::VoxelGrid<PointT> vg;
vg.setInputCloud(scans[0]);
double filterRes = 0.5;
vg.setLeafSize(filterRes, filterRes, filterRes);
typename pcl::PointCloud<PointT>::Ptr cloudFiltered (new pcl::PointCloud<PointT>);
vg.filter(*cloudFiltered);

if(matching == Icp)
    // Change 0 to 3 (or other positive number)
    transform = ICP(mapCloud, cloudFiltered, pose, 3);
