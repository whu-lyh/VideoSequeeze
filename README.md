### Usage
This repository is used to sequeeze a normal video to a n times faster.   
__But__, i found that there are many ways to relize this, such as ffmpeg and adjust the speed while roamming, etc.   
OpenCV requires being complied with __ffmepg__, which i didn't have the condition and many video format(.mp4) is not well supported.   
Under Linux   
1. Install ffmepg   
sudo apt install ffmpeg   
2. Speed or slow down the video
***
4 times faster   
ffmpeg -i origin.mp4 -vf  "setpts=0.25*PTS" UpTheOrigin.mp4  
4 times slower   
ffmpeg -i origin.mp4 -vf "setpts=4*PTS" DownTheOrigin.mp4  
***
3. Change the video format  
***
ffmpeg -i origin.ogv -vcodec h264 output.mp4  
ffmpeg -i origin.ogv -vcodec mpeg4 output.mp4  
ffmpeg -i origin.ogv -vcodec libxvid output.mp4  
ffmpeg -i origin.mp4 -vcodec wmv1 output.wmv  
ffmpeg -i origin.mp4 -vcodec wmv2 output.wmv  
***
4. More resources  
Please dive the [Blog](https://blog.csdn.net/WuLex/article/details/101513018).