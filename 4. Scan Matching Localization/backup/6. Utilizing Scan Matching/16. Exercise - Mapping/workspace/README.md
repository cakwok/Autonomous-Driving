# Exercise: Mapping

Complete the TODO's in `map-main.cpp`.

## Compiling

**Make sure the GPU is enabled**


```
cd /home/workspace
cmake .
make
```

## Run the code

```
su - student // Ignore Permission Denied, if you see student@ you are good
cd /home/workspace
./run_carla.sh
// Create new tab
cd /home/workspace
./cloud_mapper // Might have core dump on start up, just rerun if so. Crash doesn't happen more than a couple of times
```

Note that any visualizations will appear only the remote desktop; if you work in the workspace IDE you will need to click on the "Desktop" button in the bottom right, and only run the executable from the terminal within the remote desktop to view them.