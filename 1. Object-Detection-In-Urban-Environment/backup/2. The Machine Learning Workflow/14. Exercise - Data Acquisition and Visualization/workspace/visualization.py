import glob
import json
import os

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
from PIL import Image

from utils import get_data
from pylab import *

def viz(ground_truth):
    """
    create a grid visualization of images with color coded bboxes
    args:
    - ground_truth [list[dict]]: ground truth data
    """
    
    #pre process dictionary
    gtruth_dict = {}
    
    for gt in ground_truth:
        gtruth_dict[gt["filename"]] = gt
        
    print("\n\n\n")
    print(gtruth_dict)
    
    #draw bbox
    paths = glob.glob("data/images/*")
    
    f, ax = plt.subplots(4, 5, figsize=(20, 10))
    
    for i, path in enumerate(paths):
       
        x = i % 4
        y = i % 5

        img = Image.open(path)
        filename = os.path.basename(path)       #take only the filename from the full path
        
        bboxes = gtruth_dict[filename]['boxes']
        
        for bbox in bboxes:
            y1, x1, y2, x2 = bbox
            draw_bbox = Rectangle((x1, y1), x2 - x1, y2 - y1, facecolor='none', edgecolor='red')
            ax[x, y].add_patch(draw_bbox)
            
        ax[x ,y].axis('off')
        ax[x, y].imshow(img)
    
       
    plt.show()

if __name__ == "__main__": 
    ground_truth, _ = get_data()
    print(ground_truth)
    viz(ground_truth)