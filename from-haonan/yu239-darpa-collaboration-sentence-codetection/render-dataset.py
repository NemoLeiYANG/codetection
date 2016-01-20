#!/usr/bin/python

import os
import cv2
import numpy as np
import glob

vout = cv2.VideoWriter("/tmp/codetection-results.avi", cv2.cv.CV_FOURCC('m', 'p', '4', 'v'), 30, (768,480))

def put_frame(frame, w1, h1, w2, h2):
    img = np.zeros((h2,w2,3), np.uint8)
    sw = (w2 - w1) / 2
    sh = (h2 - h1) / 2
    ew = sw + w1
    eh = sh + h1
    img[sh:eh, sw:ew] = frame
    vout.write(img)
    
def intro_frame(height, width, text, duration):
    img = np.zeros((height,width,3), np.uint8)
    cv2.putText(img, text, (width/3, height/2), cv2.FONT_HERSHEY_SIMPLEX, 1, (255,255,255), 1)
    for j in range(duration):
        put_frame(img, width, height, 768, 480)

if __name__ == "__main__":
    datasets = ["house", "CAD"]
    titles = ["Our new dataset", "Our subset of CAD-120"]
    prefix = ["videos-house-amt-", ""]
    for d in range(len(datasets)):
        dataset = datasets[d]
        if d == 0:
            sets_n = 10
            width, height = (768, 432)
        else:
            sets_n = 5
            width, height = (640, 480)

        intro_frame(height, width, titles[d], 30)

        for i in range(sets_n):
            intro_frame(height, width, "Codetection set %d" % (i+1), 30)

            for r in range(3):
                intro_frame(height, width, "Run %d" % (i+1), 30)

                ## dump the frames
                path = glob.glob("/aux/yu239/codetection-results-amt-%s/%s%d_%d/*/new-tracked.mp4"
                                 % (dataset,prefix[d],r+1,i+1))
                vin = cv2.VideoCapture(path[0])
                while True:
                    ret, frame = vin.read()
                    if not ret:
                        break
                    put_frame(frame, width, height, 768, 480)
                vin.release()
                
                
