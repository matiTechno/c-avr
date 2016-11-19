#include <util/delay.h>
#include "diod.h"

int main()
{
	Diod<PortB> diod(PB1);

	for(;;)
	{
		diod.toggle();
		_delay_ms(1000);
	}
}
