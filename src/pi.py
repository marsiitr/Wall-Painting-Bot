# -*- coding: utf-8 -*-
"""
Created on Tue Feb 12 20:02:33 2019

@author: Purvi
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt
import serial

def main():
    path1 = "images\\Pooh.jpg"
    path2 = "images\\test1.tif"
    path3 = "images\\test2.tiff"
    path4 = "images\\test3.jpg"
    path5 = "images\\test5.png"
    img = cv2.imread(path1, 1)
    img0 = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    ##res = cv2.resize(img,(2*width, 2*height),interpolation = cv2.INTER_CUBIC)
    height,width = img.shape[:2]
    print(img.shape)
    ##print(img.item(100,100,0))
    
    for i in range (img.shape[0]):
        for j in range (img.shape[1]):
            if img.item(i,j,0)>127:
                if img.item(i,j,1)>127:
                    if img.item(i,j,2)<127:
                        img.itemset((i,j,0),255)
                        img.itemset((i,j,1),255)
                        img.itemset((i,j,2),0)
                    else:
                        img.itemset((i,j,0),255)
                        img.itemset((i,j,1),255)
                        img.itemset((i,j,2),255)
                else :
                    img.itemset((i,j,0),255)
                    img.itemset((i,j,1),0)
                    img.itemset((i,j,2),0)
            else:
                if img.item(i,j,1)<127:
                    if img.item(i,j,2)>127:
                        img.itemset((i,j,0),0)
                        img.itemset((i,j,1),0)
                        img.itemset((i,j,2),255)
                    else:
                        img.itemset((i,j,0),0)
                        img.itemset((i,j,1),0)
                        img.itemset((i,j,2),0)
                else:
                    img.itemset((i,j,0),127 )
                    img.itemset((i,j,1),255)
                    img.itemset((i,j,2),0)
                    
    ##resizing image according to the constraints wall height=1m marker_stroke_width=3mm 
    baseheight = 166
    ratio = baseheight/img.shape[0]
    basewidth = int(ratio*img.shape[1])
    print(basewidth)
    img1 = cv2.resize(img, (basewidth,baseheight), interpolation = cv2.INTER_CUBIC)
    
    
    images = [img0, img1]
    for i in range (2):
        plt.subplot(1,2,i+1)
        plt.imshow(images[i])
        plt.show()
        
    
    ##obtaining pixels of all colors black=0 red=1 yellow=2 green=3 blue=4 white=5
    color = [[0 for x in range(basewidth)] for y in range(baseheight)]
    for i in range (baseheight):
        for j in range (basewidth):
            if img1.item(i,j,2)==0:
                if img1.item(i,j,1)==0:
                    if img1.item(i,j,0)==0:
                        ##color black
                        color[i][j] = 0
                    else:
                        ##color red
                        color[i][j] = 1
                else:
                    if img1.item(i,j,0)==255:
                        ##color yellow
                        color[i][j] = 2
                    else:
                        ##color green
                        color[i][j] = 3
            else:
                if img1.item(i,j,0)==0:
                    ##color blue
                    color[i][j] = 4
                else:
                    ##color white
                    color[i][j] = 1
    ##for i in range(len(black)):
    ##    for j in range(len(black[i])):
    ##        print (j,end=" ")
    ##    print()
    ##for i in range (basewidth):
    ##    print(img.item(250,i,2))
    """for i in range(80):
        for  j in range(80):
            print(color[i][j], end = ",")
        print('\n')"""
        
        

    ##for serial transmission
    
    
    
    
    """##ser = serial.Serial('COM6',9600)
    ##k = ser.readline().decode()
    for i in range(baseheight):
        for j in range(basewidth):
            if color[i][j]!=5:
                print(str(j)+"#"+str(i)+"#"+str(color[i][j]))
                ###ser.write((str(j))+"#"+(str(i))+"#"+(str(color[i][j])+"/n").encode('utf-8'))
                k = 'B'
                print(k)
                ###k = ser.readline().decode()
                print(k)
                if(k[0]=='A'):
                    continue
                else:
                    ###while(k[0]!='A'):
                        ##print(k)
                        ###k = ser.readline().decode()
                    print(k)"""
                    
    
            
    


if __name__=="__main__":
    main()