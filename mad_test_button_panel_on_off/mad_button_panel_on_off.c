#include <furi.h>
#include <furi_hal.h>

#include <gui/gui.h>
#include <input/input.h>

#include "mad_test_button_panel_on_off_icons.h"

typedef enum {
    MyEventTypeKey,
    MyEventTypeDone,
} MyEventType;

typedef struct {
    MyEventType type; // The reason for this event.
    InputEvent input; // This data is specific to keypress data.
} MyEvent;

FuriMessageQueue* queue;
int x = 32;
int y = 48;

static void my_input_callback(InputEvent* input_event, void* context) {
    UNUSED(context);
    if(input_event->type == InputTypeShort) {
        if(input_event->key == InputKeyLeft) x--;
        if(input_event->key == InputKeyRight) x++;
        if(input_event->key == InputKeyUp) y--;
        if(input_event->key == InputKeyDown) y++;
        if(input_event->key == InputKeyBack) {
            MyEvent event;
            event.type = MyEventTypeDone;
            furi_message_queue_put(queue, &event, FuriWaitForever);
        }
    }
}

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

static void my_draw_enter_3(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 41, 5, &I_Off_hvr_25x27);
}

static void my_draw_enter_4(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 41, 35, &I_On_hvr_25x27);
}

static void my_draw_enter_5(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 70, 5, &I_Off_hvr_25x27);
}

static void my_draw_enter_6(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 70, 35, &I_On_hvr_25x27);
}

static void my_draw_enter_7(Canvas* canvas, void* context) {
    UNUSED(context);
    my_draw_background(canvas, context);
    canvas_draw_icon(canvas, 99, 5, &I_Off_hvr_25x27);
}

static void my_draw_enter_8(Canvas* canvas, void* context) {
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

    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_background, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_1, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_2, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_3, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_4, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_5, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_6, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_7, NULL);
    //
    //    furi_delay_ms(1000);
    //
    //    view_port_draw_callback_set(view_port, my_draw_enter_8, NULL);
    //
    //    furi_delay_ms(5000);
    //
    gui_remove_view_port(gui, view_port);
    return 0;
}