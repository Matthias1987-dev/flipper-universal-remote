#include <furi.h>
#include <furi_hal.h>

#include <gui/gui.h>
#include <input/input.h>
#include "mad_test_button_panel_on_off_icons.h"



void my_draw_background(Canvas* canvas, void* context) {
    UNUSED(context);
    canvas_draw_icon(canvas, 12, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 12, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 41, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 41, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 70, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 70, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 99, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 99, 35, &I_On_25x27);
}

void my_draw_enter_1(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 12, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_2(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 12, 35, &I_On_hvr_25x27);
}

void my_draw_enter_3(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 41, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_4(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 41, 35, &I_On_hvr_25x27);
}

void my_draw_enter_5(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 70, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_6(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 70, 35, &I_On_hvr_25x27);
}

void my_draw_enter_7(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 99, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_8(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 99, 35, &I_On_hvr_25x27);
}

int mad_test_button_panel_on_off_app(void* p) {
    UNUSED(p);

    //Show directions to user.
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, my_draw_background, NULL);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);



int pos = 1;
do {
if (pos == 1){view_port_draw_callback_set(view_port, my_draw_enter_1, NULL);}
if (pos == 2){view_port_draw_callback_set(view_port, my_draw_enter_2, NULL);}
if (pos == 3){view_port_draw_callback_set(view_port, my_draw_enter_3, NULL);}
if (pos == 4){view_port_draw_callback_set(view_port, my_draw_enter_4, NULL);}
if (pos == 5){view_port_draw_callback_set(view_port, my_draw_enter_5, NULL);}
if (pos == 6){view_port_draw_callback_set(view_port, my_draw_enter_6, NULL);}
if (pos == 7){view_port_draw_callback_set(view_port, my_draw_enter_7, NULL);}
if (pos == 8){view_port_draw_callback_set(view_port, my_draw_enter_8, NULL);}

        furi_delay_ms(1000);
        pos++;
while (pos == 8);
}

    gui_remove_view_port(gui, view_port);
    return 0;
}