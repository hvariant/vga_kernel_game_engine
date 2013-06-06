#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "proc.h"
#include "global.h"

PUBLIC void keyboard_irq(int irq){
  char code;
  static int counter = 0;
  static int first = 1;
  char status = in_byte(0x64);

  if(first){
    disp_pos = 0;
    first = 0;
  }

  if(status & 1){
    code = in_byte(0x60);
    if(code == 0xE0 || code == 0xE1){
      //nothing
    } else {
      if(!(code & 0x80)){
        if(code >= 0x23 && code <= 0x26){
          if(keys_len < KEY_BUFFER_SIZE){
            keys[keys_len++] = code;
          }
        }
      }
    }
  }

}

