# ICT-v5-sim28ml_L70r
This version ads support for GPS modules with the MTK3337 chipset, like SIM28ML and Quectel L70r, it will put the gps in "ballloon mode" that makes it work over 10000m as 
well as switching the gps on and of by sw commands, hw switching is still present as an option.

OBS!-- Untested -- For the balloon mode to work if the board waking up at over 10km we have to rely on the wdt to work or that the gps starts before the 328.
Note - set BOR to 2.7v in the 328 to delay the start, making sure the gps have had time to start and is ready to accept commands (balloon mode) from the 328.
