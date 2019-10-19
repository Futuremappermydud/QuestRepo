# Quest Tips!

Here are a few of the tips I found out after months of using the Quest!

## Capture tip!

On quest we are able to record what we are seeing in the HMD!
Well the problem with the default settings is the resolution and the bitrate!
After doing my share of research I've found out options to make your Quest recordings look better!
**WARNING This requires the Quest to be in devmode / usage of SideQuest, I, Oculus or any other aren't responsable for lag spikes or if something happens.**

We are going to use the inbuilt ADB terminal inside of SideQuest (It's the button with name "Run ADB Commands")
*adb shell setprop debug.oculus.capture.width 1920* - This changes the width of video you are capturing. 
*adb shell setprop debug.oculus.capture.width 1080* - This changes the height of video you are capturing. 
*adb shell setprop debug.oculus.capture.bitrate x* - this changes the bitrate the value is in bits so if you want 50 megabit 
then the correct value instead of x would be 50000000.
This doesn't change the FOV of the recording, this is like cutting parts of the square but it will be easier for people to watch
since the video is wider and now is in HD.

This can cause lag and if you are seeing it affects your gameplay, turn on and off the Quest and everything should be restarted to normal!

If you got modded BeatSaber I recommend you getting the [QParticles](https://github.com/Rugtveit/QuestRepo/tree/master/QuestMods/QParticles) mod that removes particles whenever you hit a Note! 
This helps towards compression and making it easier for the viewer to see what happens!
