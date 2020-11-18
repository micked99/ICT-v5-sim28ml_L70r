/*
   Timing Schedule
*/

void TXtiming() // Timing
{
  // run additional scripts here to generate data prior to TX if there is a large delay involved.
    if ((timeStatus() == timeSet) && (second() == 0) && (minute() >= 0))
    {
    setGPStime();
    if ((minute() % 02 == 0) && (second() <= 2)) // TX WSPR standard message
    {
      telemetry_set = true;
      loc4calc(); // Get position and update 4-char locator, 6-char locator and last 2 chars of 8-char locator
      call_telem(); // Update WSPR telemetry callsign based on previous information : position and altitude in meters
      loc_dbm_telem(); // Update WSPR telemetry locator and dbm. Get temperature, voltage, speed in knots, GPS status and sats number
      Serial.write("$PMTK161,0*28\r\n"); delay(800); // GPS Sleep 
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      Serial.write("$PMTK101*32\r\n"); delay(50); //Hotstart
    }
    }
    }
