/**
 * HelloWorld - LilyGO T-Watch 2020 V3
 *
 * Displays "Hello World" on the watch screen.
 * 
 * Board:  T-Watch 2020 V3
 * Flash:  4MB
 * PSRAM:  Enabled
 * Upload Speed: 921600
 */

#include "config.h"

TTGOClass *ttgo;

void setup()
{
    Serial.begin(115200);

    // Get the TTGO singleton
    ttgo = TTGOClass::getWatch();

    // Initialize the watch hardware
    ttgo->begin();

    // Turn on the backlight
    ttgo->openBL();

    // Clear screen with black background
    ttgo->tft->fillScreen(TFT_BLACK);

    // ---- Draw "Hello World" ----
    // Center text on 240x240 display
    ttgo->tft->setTextDatum(MC_DATUM);          // Middle-center alignment
    ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK);
    ttgo->tft->drawString("Hello World", 120, 120, 4);  // font 4 = large
}

void loop()
{
    // Nothing to do — message stays on screen
    delay(1000);
}
