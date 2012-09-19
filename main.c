/*
 * EBike Smart Controller
 *
 * Copyright (C) Jorge Pinto aka Casainho, 2012.
 *
 *   casainho [at] gmail [dot] com
 *     www.casainho.net
 *
 * Released under the GPL License, Version 3
 */

#include "lpc210x.h"
#include "system.h"
#include "isrsupport.h"
#include "timers.h"
#include "pwm.h"
#include "main.h"
#include "ios.h"
#include "motor.h"

/*
 * Pins connections
 * (please refer to KU63 schematic)
 *
 * LPC2103 P0.0 --> CPU1
 * LPC2103 P0.1 --> CPU3
 * LPC2103 P0.2 --> CPU5
 * LPC2103 P0.12 (PWM; MAT1.0) --> CPU44 (inverted logic on hardware)
 * LPC2103 P0.13 (PWM; MAT1.1) --> CPU2 (inverted logic on hardware)
 * LPC2103 P0.19 (PWM; MAT1.2) --> CPU4 (inverted logic on hardware)
 */

int main (void)
{
  /* Initialize the system */
  system_init ();
  timer0_init ();
  timer2_init ();
  enableIRQ ();
  pwm_init ();
  ios_init ();

  update_duty_cycle (50); // 50 --> 5% duty-cycle
  timer0_set_us (10000);
  timer0_start ();

  while (1)
  {
    delay_us (1000000);
    debug_on ();
    delay_us (330000);
    debug_on ();
  }
}
