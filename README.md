# weewx-utilities
Support code for the [weewx](https://github.com/weewx/weewx) weather system software package

Some of it is just useful for my personal system, some may be useful for others.

# Contents
## Drivers
### WMR300x
Experimental modes for the Oregon Scientific WMR300 model weather station.
This is basically the code shipped with the main weewx product, to which I have added
1. use of libusb1 (rather than the default libusb0), and
2. a bit more debugging code to help understand the operation of the quirky USB interface.


### GW1000
A driver for the EcoWitt gw1000 model using the original API on port 45000.
This has largely been supplanted by the http-based driver, for models GW1100 and later.

## Skins
My modified Seasons skin that combines results from the two weather stations.
