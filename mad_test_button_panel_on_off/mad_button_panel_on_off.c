#include <furi.h>
#include <furi_hal.h>
#include <stdlib.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <input/input.h>
#include "mad_test_button_panel_on_off_icons.h"

// This is the position of the image on the screen
// 1,1 is the first line left
// 2,1 is the first line right
// 1,2 is the second line left
// 2,2 is the second line right
// 1,3 is the third line left
// 2,3 is the third line right
// 1,4 is the fourth line left
// 2,4 is the fourth line right
//
//List of the x and y
//
//enter_1   x=1     Y=1
//enter_2   x=2     Y=1
//enter_3   x=1     y=2
//enter_4   x=2     y=2
//enter_5   x=1     y=3
//enter_6   x=2     y=3
//enter_7   x=1     y=4
//enter_8   x=2     y=4
//

// struct definition copy from boxmover
//https://github.com/at-manos/flipper-swdocs/blob/main/docs/your-first-program/code-so-far/gui/box_mover.c
//
typedef struct {
    int x;
    int y;
} ButtonPosition;

typedef struct {
    ButtonPosition* position;
} Button;

Button* button_alloc() {
    Button* instance = malloc(sizeof(Button));
    instance->position = malloc(sizeof(ButtonPosition));
    instance->position->x = 1;
    instance->position->y = 1;

    return instance;
}

void button_free(Button* instance) {
    free(instance->position);
    free(instance);
}
// my_draw_background is a function that draw the background of the application
// greatet from me.
// my_draw_enter_1 to my_draw_enter_8 are function that draw the background and
// the icon of the button that is selected
// greatet from me.
// my_input_callback is a function that put the event in the queue
// greatet from jamison.
// mad_test_button_panel_on_off_app is the main function of the application
// that call the other function
// greatet from me.
//
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

void my_input_callback(InputEvent* event, void* context) {
    furi_message_queue_put((FuriMessageQueue*)context, event, FuriWaitForever);
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

int32_t mad_test_button_panel_on_off_app(void* p) {
    UNUSED(p);
    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    //Show directions to user.
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, my_draw_background, NULL);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    //InputEvent event;

    //bool running = true;
    //do {
    //if(furi_message_queue_get(event_queue, &event, 100) == FuriStatusOk) {
    //if((event.type == InputTypePress) || (event.type == InputTypeRepeat)) {
    //if(event.type == InputTypePress) {
    //if(event.key == InputKeyUp) {
    //image_position.y--;
    //if(image_position.y < 1) {
    //image_position.y = 1;
    //}
    //} else if(event.key == InputKeyDown) {
    //image_position.y++;
    //if(image_position.y > 2) {
    //image_position.y = 2;
    //}
    //} else if(event.key == InputKeyLeft) {
    //image_position.x--;
    //if(image_position.x < 1) {
    //image_position.x = 1;
    //}
    //} else if(event.key == InputKeyRight) {
    //image_position.x++;
    //if(image_position.x > 4) {
    //image_position.x = 4;
    //}
    //}
    //if(event.key == InputKeyBack) {
    //running = false;
    //}
    // Set the view port draw callback based on the new image position
    if(image_position.y == 1 && image_position.x == 1) {
        view_port_draw_callback_set(view_port, my_draw_enter_1, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 2 && image_position.x == 1) {
        view_port_draw_callback_set(view_port, my_draw_enter_2, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 1 && image_position.x == 2) {
        view_port_draw_callback_set(view_port, my_draw_enter_3, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 2 && image_position.x == 2) {
        view_port_draw_callback_set(view_port, my_draw_enter_4, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 1 && image_position.x == 3) {
        view_port_draw_callback_set(view_port, my_draw_enter_5, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 2 && image_position.x == 3) {
        view_port_draw_callback_set(view_port, my_draw_enter_6, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 1 && image_position.x == 4) {
        view_port_draw_callback_set(view_port, my_draw_enter_7, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    } else if(image_position.y == 2 && image_position.x == 4) {
        view_port_draw_callback_set(view_port, my_draw_enter_8, NULL);
        view_port_input_callback_set(view_port, my_input_callback, event_queue);
    }
    //}
    //}
    //}
    //} while(running);
    gui_remove_view_port(gui, view_port);

    return 0;
}
