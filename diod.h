/*
 * diod.h
 *
 *  Created on: Nov 18, 2016
 *      Author: matitechno
 */

#ifndef DIOD_H_
#define DIOD_H_

#include <avr/io.h>

class DiodBase
{
public:
	DiodBase(const DiodBase&) = delete;
	DiodBase& operator=(const DiodBase&) = delete;

	void on() const
	{
		*dataReg |= (1<<pin);
	}
	void off() const
	{
		*dataReg &= ~(1<<pin);
	}
	void toggle() const
	{
		*dataReg ^= (1<<pin);
	}

protected:
	DiodBase(const uint8_t pin, volatile uint8_t* const dataReg,
			volatile uint8_t* const dataDirReg):
				pin(pin),
				dataReg(dataReg),
				dataDirReg(dataDirReg)
{
		*dataDirReg |= (1<<pin);
}

private:
	const uint8_t pin;
	volatile uint8_t* const dataReg;
	volatile uint8_t* const dataDirReg;
};

template<typename T>
class Diod;

class PortB{};
class PortC{};
class PortD{};

template<>
class Diod<PortB>: public DiodBase
{
public:
	Diod(const uint8_t pin):
		DiodBase(pin, &PORTB, &DDRB)
{}
};

template<>
class Diod<PortC>: public DiodBase
{
public:
	Diod(const uint8_t pin):
		DiodBase(pin, &PORTC, &DDRC)
{}
};

template<>
class Diod<PortD>: public DiodBase
{
public:
	Diod(const uint8_t pin):
		DiodBase(pin, &PORTD, &DDRD)
{}
};

#endif /* DIOD_H_ */
