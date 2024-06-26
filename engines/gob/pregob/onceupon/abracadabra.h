/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * This file is dual-licensed.
 * In addition to the GPLv3 license mentioned above, this code is also
 * licensed under LGPL 2.1. See LICENSES/COPYING.LGPL file for the
 * full text of the license.
 *
 */

#ifndef GOB_PREGOB_ONCEUPON_ABRACADABRA_H
#define GOB_PREGOB_ONCEUPON_ABRACADABRA_H

#include "gob/pregob/onceupon/onceupon.h"

namespace Gob {

namespace OnceUpon {

class Abracadabra : public OnceUpon {
public:
	Abracadabra(GobEngine *vm);
	~Abracadabra() override;

	void run() override;

protected:
	const StorkParam &getStorkParameters() const override;

private:
	/** Definition of the menu button that leads to the animal names screen. */
	static const MenuButton kAnimalsButtons;

	/** Definition of the buttons that make up the animals in the animal names screen. */
	static const MenuButton kAnimalButtons[];
	/** File prefixes for the name of each animal. */
	static const char *kAnimalNames[];

	// Parameters for the stork section.
	static const MenuButton kStorkHouses[];
	static const Stork::BundleDrop kStorkBundleDrops[];
	static const struct StorkParam kStorkParam;
};

} // End of namespace OnceUpon

} // End of namespace Gob

#endif // GOB_PREGOB_ONCEUPON_ABRACADABRA_H
