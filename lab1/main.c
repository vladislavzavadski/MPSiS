#include <msp430.h>


void main(void) {
    volatile int flag = 0;
    volatile int i=0;
    volatile int exit = 0;

	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    P8OUT = 0;
    P8DIR = BIT1;

    P1REN |= BIT7;
    P1OUT |= BIT7;
    P1DIR &= ~BIT7;

    P2REN |= BIT2;
    P2OUT |= BIT2;
    P2DIR &= ~BIT2;

    while(1){

    	while((P2IN & BIT2)==BIT2 && (P1IN & BIT7)==BIT7){//Пока никакая кнопка не нажата
    	
        	if(flag == 1){ // Если режим моргания
    			P8OUT ^= BIT1;//Меняем значение бита на противоположное
    			for(i=0; i<4000; i++){} // Задержка
    		}
    	
        }

    	if(flag == 1){ // Переключаем режим
    		flag = 0;
    	}
    	else{
    		flag = 1;
    	}

    	while((P2IN & BIT2) != BIT2 || (P1IN & BIT7) != BIT7){} //Ждем пока кнопка не будет отпущена
    }
}

