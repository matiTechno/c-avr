extern "C"
{
#include <avr/io.h>
#include <util/delay.h>
}

// using pointers instead of references becuase of warning
class Diod
{
public:
	Diod(volatile uint8_t* dataDirReg, volatile uint8_t* dataReg, uint8_t pin):
		dataDirReg(dataDirReg),
		dataReg(dataReg),
		pin(pin)
{
		*dataDirReg |= (1<<pin);
}
	Diod(const Diod&) = delete;
	Diod& operator=(const Diod&) = delete;

	void toggle()
	{
		*dataReg ^= (1<<pin);
	}
	void on()
	{
		*dataReg |= (1<<pin);
	}
	void off()
	{
		*dataReg &= ~(1<<pin);
	}

private:
	volatile uint8_t* dataDirReg;
	volatile uint8_t* dataReg;
	const uint8_t pin;
};


int main()
{
	Diod diod1(&DDRB, &PORTB, PB1);

	for(;;)
	{
		diod1.toggle();
		_delay_ms(1000);
	}
}
