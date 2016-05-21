# VCSimulinkTlbx
Simulink Toolbox for Real-time Virtual Character Control



## Installation ##

We install the library in `%USERPROFILE%\Documents\MATLAB\VCTlbx`

For the library to load you have to add 
    addpath %USERPROFILE%\Documents\MATLAB\VHlibrary
to the file
    startup.m
in `%USERPROFILE%\Documents\MATLAB`



### Adding a Simulink library to the browser ###

* At the MATLAB® command prompt, enable the model property EnableLBRepository. Your library appears in the library browser only if this property is on when you save your library.
	`set_param(gcs,'EnableLBRepository','on');`

* Save the library in a folder in the MATLAB path
* In MATLAB, right-click the folder you saved the library to and select New File > Script. Name the file slblocks.m.

* Open `slblocks.m` and add this function to it and save.

        function blkStruct = slblocks
    	    Browser.Library = 'mylib'; 
    		Browser.Name = 'My Library'; 
    		blkStruct.Browser = Browser;

* In the Library Browser, refresh to see the new library. Right-click the library list and select **Refresh Library Browser.**


## Documentation for Blocks ##

### Gaze controller ###
* Uses the SmartBody specific "<gaze sbm:target-pos="0 0 0"/>" to set the gaze point in 3D
* Resetting the gaze is not implemented yet
* "Extent" controls what joints are involved in the gaze behavior (potentially SmartBody specific)
	* 0.00 ... 0.25: EYES
	* 0.25 ... 0.50: EYES, NECK
	* 0.50 ... 0.75: EYES, NECK, CHEST
	* 0.75 ... 1.00: EYES, NECK, CHEST, BACK