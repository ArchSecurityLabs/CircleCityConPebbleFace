#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x91, 0x0F, 0x4A, 0xA8, 0x2A, 0xFE, 0x48, 0xFB, 0xA2, 0x9B, 0x28, 0x1E, 0xE7, 0xED, 0xFB, 0xB1 }
PBL_APP_INFO(MY_UUID,
             "CircleCityCon App", "Arch Security Labs, LLC",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
TextLayer main_layer;

void handle_init(AppContextRef ctx) {
  window_init(&window, "Main Window");
  window_stack_push(&window, true /* Animated */);

  text_layer_init(&main_layer, GRect(0, 65, 144, 30));
  text_layer_set_text_alignment(&main_layer, GTextAlignmentCenter);
  text_layer_set_text(&main_layer, "Hello World!");
  text_layer_set_font(&main_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
  layer_add_child(&window.layer, &main_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
