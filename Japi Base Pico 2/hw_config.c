#include "hw_config.h"

// --- SPI BUS CONFIGURATIE ---
spi_t spi = {
    .hw_inst = spi1,  // Hardware SPI kanaal 1
    .miso_gpio = 12,  // RX (MISO)
    .mosi_gpio = 11,  // TX (MOSI)
    .sck_gpio = 10,   // SCK
    .baud_rate = 1000000, // 12.5 MHz is ruim voldoende en stabiel
    
    // Voorkom signaal-reflecties
    .set_drive_strength = true,
    .mosi_gpio_drive_strength = GPIO_DRIVE_STRENGTH_4MA,
    .sck_gpio_drive_strength = GPIO_DRIVE_STRENGTH_4MA
};

// --- SD KAART CONFIGURATIE ---
sd_card_t sd_cards[] = {
    {
        .pcName = "0:",
        .spi = &spi,
        .ss_gpio = 13, // CS (Chip Select)
        
        // CRUCIAAL: Zet Card Detect uit!
        // Dit voorkomt dat de bibliotheek stiekem een achtergrond-interrupt 
        // activeert die jouw VGA-scanline timing vernietigt.
        .use_card_detect = false, 
        .card_detect_gpio = 0,    
        .card_detected_true = -1,
        
        .set_drive_strength = true,
        .ss_gpio_drive_strength = GPIO_DRIVE_STRENGTH_4MA
    }
};

// ========================================================
// HIER ZIJN ALLE 4 DE VEREISTE INTERFACE FUNCTIES
// ========================================================

// 1. SD Kaart functies
size_t sd_get_num() { 
    return 1; 
}

sd_card_t *sd_get_by_num(size_t num) {
    if (num == 0) return &sd_cards[0];
    return NULL;
}

// 2. SPI Bus functies
size_t spi_get_num() { 
    return 1; 
}

spi_t *spi_get_by_num(size_t num) {
    if (num == 0) return &spi;
    return NULL;
}