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

#ifndef GOB_MULT_H
#define GOB_MULT_H

#include "gob/videoplayer.h"
#include "gob/video.h"
#include "gob/variables.h"

namespace Gob {

class Mult {
public:

#include "common/pack-start.h"	// START STRUCT PACKING

	struct Mult_AnimData {
		int8 animation;
		uint8 layer;
		uint8 frame;
		int8 animType;
		int8 order;
		int8 isPaused;
		int8 isStatic;
		int8 maxTick;
		int8 maxFrame;
		uint8 newLayer;
		int8 newAnimation;
		byte intersected;
		uint8 newCycle;
		int8 state;
		int8 nextState;
		int8 newState;
		int8 curLookDir;
		int8 isBusy;
		int8 pathExistence;
		int8 destX;
		int8 destY;
		int8 framesLeft;
		int8 stateType;
		int8 animTypeBak;
		int8 redrawAnimation;
		uint8 redrawLayer;
		uint8 redrawFrame;
		uint8 destXBak;
		uint8 destYBak;
		int8 gobDestX_maybe;
		uint8 gobDestY_maybe;
		uint8 field_1F;
		uint8 field_20;
		uint8 field_21;
		uint8 field_22;
	} PACKED_STRUCT;

	struct Mult_GobState {
		int16 animation; // .
		int16 layer;     // |- [0]
		int16 dataCount; // '
		int8 sndItem;    // .
		uint8 sndFrame;  // |
		int16 freq;      // |- [1+]
		int8 repCount;   // |
		uint8 speaker;   // '
	} PACKED_STRUCT;

	struct Mult_Object {
		VariableReference *pPosX;
		VariableReference *pPosY;
		Mult_AnimData *pAnimData;
		int16 tick;
		int16 lastLeft;
		int16 lastRight;
		int16 lastTop;
		int16 lastBottom;
		Mult_GobState **goblinStates;
		uint8 goblinX;
		uint8 goblinY;
		uint8 destX;
		uint8 destY;
		int8 gobDestX;
		int8 gobDestY;
		uint8 nearestWayPoint;
		uint8 nearestDest;
		int8 needRedraw;
		int16 newLeft;
		int16 newTop;
		int16 newRight;
		int16 newBottom;
		int16 spriteDestLeft;
		int16 spriteDestTop;
		int16 spriteDestRight;
		int16 spriteDestBottom;
		uint32 videoSlot;
		int16 lastFrameIndex;
		int16 field_32[3];
		byte* field_3C;
		char animName[16];
		int8 field_50;
		VariableReferenceArray *animVariables;
		//bool ownAnimVariables;
	} PACKED_STRUCT;

	struct Mult_StaticKey {
		int16 frame;
		int16 layer;
	} PACKED_STRUCT;

	struct Mult_AnimKey {
		uint16 frame;
		int16 layer;
		int16 posX;
		int16 posY;
		int16 order;
	} PACKED_STRUCT;

	struct Mult_TextKey {
		int16 frame;
		int16 cmd;
		char unknown[18];
		byte script[6];
	} PACKED_STRUCT;

	struct Mult_PalKey {
		int16 frame;
		int16 cmd;
		int16 rates[4];
		int16 unknown0;
		int16 unknown1;
		int8 subst[16][4];
	} PACKED_STRUCT;

	struct Mult_PalFadeKey {
		int16 frame;
		int16 fade;
		int16 palIndex;
		int8 flag;
	} PACKED_STRUCT;

	struct Mult_SndKey {
		int16 frame;
		int16 cmd;
		int16 freq;
		int16 fadeLength;
		int16 repCount;
		int16 resId;
		int16 soundIndex;
	} PACKED_STRUCT;

	struct Mult_ImdKey {
		int16 frame;
		int16 imdFile;
		int16 field_4;
		int16 field_6;
		uint16 flags;
		int16 palFrame;
		int16 lastFrame;
		int8 palStart;
		int8 palEnd;
	} PACKED_STRUCT;

	struct Mult_Data {
		int16 palFadeKeysCount;
		Mult_PalFadeKey *palFadeKeys;

		int16 palKeysCount;
		Mult_PalKey *palKeys;

		int16 staticKeysCount;
		Mult_StaticKey *staticKeys;
		int16 staticIndices[10];
		bool staticLoaded[10];
		uint8 staticCount;

		int16 animKeysCount[4];
		Mult_AnimKey *animKeys[4];
		int16 animIndices[10];
		uint8 animCount;

		bool animLoaded[10];
		int16 animKeysFrames[4];
		int16 animKeysStartFrames[4];
		int16 animKeysStopFrames[4];
		int16 animKeysIndices[4][4];
		int8 animDirection;

		int16 textKeysCount;
		Mult_TextKey *textKeys;

		int16 sndKeysCount;
		Mult_SndKey *sndKeys;

		int16 sndSlotsCount;
		int16 sndSlot[60];
		int16 frameRate;

		Video::Color fadePal[5][16];
		int16 animObjs[4][4];
		int16 palAnimIndices[4];
		int16 frameStart;

		int16 imdKeysIndices[4][4];

		int16 imdKeysCount[4];
		Mult_ImdKey *imdKeys[4];
		int16 imdIndices[4];
		char *imdFiles;
		char *somepointer10; // ?
		byte *execPtr;
	} PACKED_STRUCT;

#include "common/pack-end.h"	// END STRUCT PACKING

	// Globals

	Mult_Data *_multData;

	int16 _frame;

	int16 _objCount;
	Mult_Object *_objects;

	int16 *_renderData;
	Mult_Object **_renderObjs;

	int8 *_orderArray;

	SurfacePtr _animSurf;
	int16 _animLeft;
	int16 _animTop;
	int16 _animWidth;
	int16 _animHeight;

	void initAll();
	void freeAll();
	void checkFreeMult();
	void freeMult(bool freeObjectSprites = false);
	void zeroMultData();
	void playMult(int16 startFrame, int16 endFrame, char checkEscape,
			char handleMouse);

	int openObjVideo(const Common::String &file, VideoPlayer::Properties &properties, int animation);
	void closeObjVideo(Mult_Object &object);
	void clearObjectVideos();

	virtual void loadMult(int16 resId) = 0;
	virtual void freeMultKeys() = 0;
	virtual bool hasMultData(uint16 multIndex) = 0;
	virtual void setMultData(uint16 multIndex) = 0;
	virtual void zeroMultData(uint16 multIndex) = 0;
	virtual void multSub(uint16 multIndex) = 0;
	virtual void animate() = 0;

	Mult(GobEngine *vm);
	virtual ~Mult();

protected:
	int16 _index;
	int16 _counter;
	bool _animDataAllocated;

	Mult_Data *_multDatas[8];

	bool _doPalSubst;

	Variables *_animArrayX;
	Variables *_animArrayY;
	Mult_AnimData *_animArrayData;

	int16 _palKeyIndex;
	Video::Color *_oldPalette;
	Video::Color _palAnimPalette[256];
	int16 _palAnimKey;
	int16 _palAnimRed[4];
	int16 _palAnimGreen[4];
	int16 _palAnimBlue[4];

	char _palFadingRed;
	char _palFadingGreen;
	char _palFadingBlue;

	GobEngine *_vm;

	void drawText(bool &stop, bool &stopNoClear);
	void prepPalAnim(bool &stop);
	void doPalAnim();
	void doFadeAnim(bool &stop);
	void doSoundAnim(bool &stop, int16 frame);

	virtual void playMultInit() = 0;
	virtual void drawStatics(bool &stop) = 0;
	virtual void drawAnims(bool &stop) = 0;
	virtual void newCycleAnim(Mult_Object &animObj) = 0;
};

class Mult_v1 : public Mult {
public:
	Mult_v1(GobEngine *vm);
	~Mult_v1() override {}

	void loadMult(int16 resId) override;
	void freeMultKeys() override;
	bool hasMultData(uint16 multIndex) override;
	void setMultData(uint16 multIndex) override;
	void zeroMultData(uint16 multIndex) override;
	void multSub(uint16 multIndex) override;
	void animate() override;

protected:
	void playMultInit() override;
	void drawStatics(bool &stop) override;
	void drawAnims(bool &stop) override;
	void newCycleAnim(Mult_Object &animObj) override;
};

class Mult_v2 : public Mult_v1 {
public:
	Mult_v2(GobEngine *vm);
	~Mult_v2() override;

	void loadMult(int16 resId) override;
	void freeMultKeys() override;
	bool hasMultData(uint16 multIndex) override;
	void setMultData(uint16 multIndex) override;
	void zeroMultData(uint16 multIndex) override;
	void multSub(uint16 multIndex) override;
	void animate() override;

protected:
	void playMultInit() override;
	void drawStatics(bool &stop) override;
	void drawAnims(bool &stop) override;
	void newCycleAnim(Mult_Object &animObj) override;

	void loadImds(Common::SeekableReadStream &data);
	void playImd(const char *imdFile, Mult_ImdKey &key, int16 dir, int16 startFrame);

	void advanceObjects(int16 index);
	void advanceAllObjects();
};

} // End of namespace Gob

#endif // GOB_MULT_H
