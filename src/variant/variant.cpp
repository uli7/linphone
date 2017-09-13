/*
 * variant.cpp
 * Copyright (C) 2017  Belledonne Communications SARL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY {} without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "variant.h"

// =============================================================================

using namespace std;

LINPHONE_BEGIN_NAMESPACE

class VariantPrivate {
public:
	union Value {
		int i;
		unsigned int ui;
		short s;
		unsigned short us;
		long l;
		unsigned long ul;
		long long ll;
		unsigned long long ull;
		char c;
		bool b;
		double d;
		float f;
	};

	Variant::Type type = Variant::Invalid;
	Value value = {};
};

Variant::Variant () {
	// Nothing. Construct an invalid invariant.
}

Variant::Variant (Type type) {
	// TODO.
}

Variant::Variant (const Variant &src) {
	// TODO.
}

Variant::Variant (Variant &&src) {
	// TODO.
}

Variant::Variant (int value) : Variant(Int) {
	L_D(Variant);
	d->value.i = value;
}

Variant::Variant (unsigned int value) : Variant(UnsignedInt) {
	L_D(Variant);
	d->value.ui = value;
}

Variant::Variant (short value) : Variant(Short) {
	L_D(Variant);
	d->value.s = value;
}

Variant::Variant (unsigned short value) : Variant(UnsignedShort) {
	L_D(Variant);
	d->value.us = value;
}

Variant::Variant (long value) : Variant(Long) {
	L_D(Variant);
	d->value.l = value;
}

Variant::Variant (unsigned long value) : Variant(UnsignedLong) {
	L_D(Variant);
	d->value.ul = value;
}

Variant::Variant (long long value) : Variant(LongLong) {
	L_D(Variant);
	d->value.ll = value;
}

Variant::Variant (unsigned long long value) : Variant(UnsignedLongLong) {
	L_D(Variant);
	d->value.ull = value;
}

Variant::Variant (char value) : Variant(Char) {
	L_D(Variant);
	d->value.c = value;
}

Variant::Variant (bool value) : Variant(Bool) {
	L_D(Variant);
	d->value.b = value;
}

Variant::Variant (double value) : Variant(Double) {
	L_D(Variant);
	d->value.d = value;
}

Variant::Variant (float value) : Variant(Float) {
	L_D(Variant);
	d->value.f = value;
}

Variant::Variant (const std::string &value) {
	// TODO.
}

Variant::~Variant () {
	// TODO.
}

bool Variant::operator!= (const Variant &variant) const {
	// TODO.
	return false;
}

bool Variant::operator< (const Variant &variant) const {
	// TODO.
	return false;
}

bool Variant::operator<= (const Variant &variant) const {
	// TODO.
	return false;
}

Variant &Variant::operator= (const Variant &variant) {
	// TODO.
	return *this;
}

Variant &Variant::operator= (Variant &&variant) {
	// TODO.
	return *this;
}

bool Variant::operator== (const Variant &variant) const {
	// TODO.
	return false;
}

bool Variant::operator> (const Variant &variant) const {
	// TODO.
	return false;
}

bool Variant::operator>= (const Variant &variant) const {
	// TODO.
	return false;
}

bool Variant::isValid () const {
	// TODO.
	return false;
}

void Variant::clear () {
	// TODO.
}

void Variant::swap (const Variant &variant) {
	// TODO.
}

// -----------------------------------------------------------------------------
// Number conversions.
// -----------------------------------------------------------------------------

static inline long long getValueAsNumber (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return 0;
}

static inline unsigned long long getValueAsUnsignedNumber (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return 0;
}

// -----------------------------------------------------------------------------
// Specific conversions.
// -----------------------------------------------------------------------------

static inline bool getValueAsBool (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return false;
}

static inline double getValueAsDouble (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return 0.0;
}

static inline float getValueAsFloat (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return 0.f;
}

static inline float getValueAsString (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return 0.f;
}

static inline void *getValueAsGeneric (const VariantPrivate &p, bool *soFarSoGood) {
	// TODO.
	return nullptr;
}

// -----------------------------------------------------------------------------

void Variant::getValue (int type, void *value, bool *soFarSoGood) const {
	L_D(const Variant);

	if (type <= 0 || type >= MaxDefaultTypes) {
		*soFarSoGood = false;
		// Unable to get value. It will be great to support custom types.
		return;
	}

	switch (static_cast<Type>(type)) {
		// Cast as Number.
		case Int:
			*static_cast<int *>(value) = static_cast<int>(getValueAsNumber(*d, soFarSoGood));
			break;
		case Short:
			*static_cast<short *>(value) = static_cast<short>(getValueAsNumber(*d, soFarSoGood));
			break;
		case Long:
			*static_cast<long *>(value) = static_cast<long>(getValueAsNumber(*d, soFarSoGood));
			break;
		case LongLong:
			*static_cast<long long *>(value) = getValueAsNumber(*d, soFarSoGood);
			break;
		case Char:
			*static_cast<char *>(value) = static_cast<char>(getValueAsNumber(*d, soFarSoGood));
			break;

		// Cast as Unsigned number.
		case UnsignedInt:
			*static_cast<unsigned int *>(value) = static_cast<unsigned int>(getValueAsNumber(*d, soFarSoGood));
			break;
		case UnsignedShort:
			*static_cast<unsigned short *>(value) = static_cast<unsigned short>(getValueAsNumber(*d, soFarSoGood));
			break;
		case UnsignedLong:
			*static_cast<unsigned long *>(value) = static_cast<unsigned long>(getValueAsNumber(*d, soFarSoGood));
			break;
		case UnsignedLongLong:
			*static_cast<unsigned long long *>(value) = getValueAsNumber(*d, soFarSoGood);
			break;

		// Cast as specific value.
		case Bool:
			*static_cast<bool *>(value) = getValueAsBool(*d, soFarSoGood);
			break;
		case Double:
			*static_cast<double *>(value) = getValueAsDouble(*d, soFarSoGood);
			break;
		case Float:
			*static_cast<float *>(value) = getValueAsFloat(*d, soFarSoGood);
			break;
		case String:
			*static_cast<string *>(value) = getValueAsString(*d, soFarSoGood);
			break;
		case Generic:
			*static_cast<void **>(value) = getValueAsGeneric(*d, soFarSoGood);
			break;

		case Invalid:
		case MaxDefaultTypes:
			*soFarSoGood = false;
			break;
	}
}

LINPHONE_END_NAMESPACE
