#include <furi.h>
#include <gui/gui.h>

#include "mad_test_button_panel_icons.h"

void my_draw_ende(Canvas* canvas, void* context) {
    UNUSED(context);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 5, 32, "Wird in 5 sec beendet");
}

void my_draw_button(Canvas* canvas, void* context) {
    UNUSED(context);
    canvas_draw_icon(canvas, 12, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 12, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 41, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 41, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 70, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 99, 35, &I_On_25x27);
    canvas_draw_icon(canvas, 99, 5, &I_Off_25x27);
    canvas_draw_icon(canvas, 70, 5, &I_Off_25x27);
}

void my_draw_enter_1(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 12, 35, &I_On_hvr_25x27);
}

void my_draw_enter_2(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 12, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_3(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 41, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_4(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 41, 35, &I_On_hvr_25x27);
}

void my_draw_enter_5(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 70, 35, &I_On_hvr_25x27);
}

void my_draw_enter_6(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 99, 35, &I_On_hvr_25x27);
}

void my_draw_enter_7(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 99, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_8(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 70, 5, &I_Off_hvr_25x27);
}

void my_draw_enter_9(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_button(canvas, context);
    canvas_draw_icon(canvas, 12, 35, &I_A_On_hvr_25x27);
    canvas_draw_icon(canvas, 12, 5, &I_A_Off_hvr_25x27);
    canvas_draw_icon(canvas, 41, 5, &I_B_Off_hvr_25x27);
    canvas_draw_icon(canvas, 41, 35, &I_B_On_hvr_25x27);
    canvas_draw_icon(canvas, 70, 35, &I_C_On_hvr_25x27);
    canvas_draw_icon(canvas, 99, 35, &I_C_On_hvr_25x27);
    canvas_draw_icon(canvas, 99, 5, &I_C_Off_hvr_25x27);
    canvas_draw_icon(canvas, 70, 5, &I_C_Off_hvr_25x27);
}

int mad_test_button_panel_app(void* p) {
    UNUSED(p);

    // Show directions to user.
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, my_draw_button, NULL);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_button, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_1, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_2, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_3, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_4, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_5, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_6, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_7, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_8, NULL);

    furi_delay_ms(1000);

    view_port_draw_callback_set(view_port, my_draw_enter_9, NULL);

    furi_delay_ms(10000);

    view_port_draw_callback_set(view_port, my_draw_ende, NULL);

    furi_delay_ms(1000);

    gui_remove_view_port(gui, view_port);
    return 0;
}