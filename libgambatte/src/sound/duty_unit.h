/***************************************************************************
 *   Copyright (C) 2007 by Sindre Aam�s                                    *
 *   aamas@stud.ntnu.no                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License version 2 for more details.                *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   version 2 along with this program; if not, write to the               *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef DUTY_UNIT_H
#define DUTY_UNIT_H

#include "sound_unit.h"

class DutyUnit : public SoundUnit {
	uint32_t period;
	uint32_t nextPosUpdate;
	uint8_t pos;
	uint8_t duty;
	bool high;

	void setCounter();
	void setDuty(unsigned nr1);
	void updatePos(unsigned cc);

public:
	void event();
	bool isHighState() const { return high; }
	void nr1Change(unsigned newNr1, unsigned cc);
	void nr3Change(unsigned newNr3, unsigned cc);
	void nr4Change(unsigned newNr4, unsigned cc);
	void init(unsigned cc);
	void reset();
	void resetCounters(unsigned oldCc);
	
	//intended for use by SweepUnit only.
	unsigned getFreq() const { return 2048 - (period >> 1); }
	void setFreq(unsigned newFreq, unsigned cc);
};

#endif
