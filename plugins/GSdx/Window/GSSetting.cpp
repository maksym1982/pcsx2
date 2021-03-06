/*
 *	Copyright (C) 2007-2015 Gabest
 *	http://www.gabest.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "stdafx.h"
#include "GSSetting.h"
#ifdef _WIN32
#include "resource.h"
#endif

const char* dialog_message(int ID, bool* updateText) {
	if (updateText)
		*updateText = true;
	switch (ID)
	{
		case IDC_FILTER:
			return "Control the texture filtering of the emulation.\n\n"
				"Nearest:\nAlways disable interpolation, rendering will be blocky.\n\n"
				"Bilinear Forced (excluding sprite):\nAlways enable interpolation except for sprites (FMV/Text/2D elements)."
				" Rendering is smoother but it could generate a few glitches. If upscaling is enabled, this setting is recommended over 'Bilinear Forced'\n\n"
				"Bilinear Forced:\nAlways enable interpolation. Rendering is smoother but it could generate some glitches.\n\n"
				"Bilinear PS2:\nUse same mode as the PS2. It is the more accurate option.";
		case IDC_TRI_FILTER:
			return "Control the texture tri-filtering of the emulation.\n\n"
				"None:\nNo extra trilinear filtering.\n\n"
				"Trilinear:\nUse OpenGL trilinear interpolation when PS2 uses mipmaps.\n\n"
				"Trilinear Forced:\nAlways enable full trilinear interpolation. Warning Slow!\n\n";
		case IDC_CRC_LEVEL:
			return "Control the number of Auto-CRC hacks applied to games.\n\n"
				"Automatic:\nAutomatically sets the recommended CRC hack level based on the selected renderer.\n"
				"This is the recommended setting.\n"
				"Partial will be selected for OpenGL.\nFull will be selected for Direct3D.\n\n"
				"None:\nRemove all CRC hacks.\n\n"
				"Minimum:\nEnable a couple of CRC hacks.\n\n"
				"Partial:\nFor an optimal experience with OpenGL.\n\n"
				"Full:\nFor an optimal experience with Direct3D.\n\n"
				"Aggressive:\nUse more aggressive CRC hacks.\n"
				"Removes effects in some games which make the image appear sharper/clearer.\n"
				"Affected games: AC4, DBZBT 2 & 3, FF games, GOW games, LegoBatman, MGS3, OnimushaDoD, RE4, SoTC, SMT3, SMTDDS1, SMTDDS2.\n"
				"Works as a speedhack for: BleachBB, Kunoichi, Steambot Chronicles, The Simpsons Game.";
		case IDC_SKIPDRAWHACK:
		case IDC_SKIPDRAWHACKEDIT:
		case IDC_SKIPDRAWOFFSET:
		case IDC_SKIPDRAWOFFSETEDIT:
			return "Completely skips drawing surfaces from the surface in the left box up to the surface specified in the box on the right.\n\n"
				"Use it, for example, to try and get rid of bad post processing effects.\n"
				"Step 1: Increase the value in the left box and keep the value in the right box set to the same value as the left box to find and remove a bad effect.\n"
				"Step 2: If a bad effect found with Step 1 is not completely removed yet, then without changing the value in the left box, try increasing the value in the box to right until the effect is completely gone.\n\n"
				"Note: Increase the value in the right box and keep the value in the left box set to \"1\" to reproduce the old skipdraw behaviour.";
		case IDC_ALPHAHACK:
			return "Different alpha handling. Can work around some shadow problems.";
		case IDC_OFFSETHACK:
			return "Might fix some misaligned fog, bloom, or blend effect.\n"
				"The preferred option is Normal (Vertex) as it is most likely to resolve misalignment issues.\n"
				"The special cases are only useful in a couple of games like Captain Tsubasa.";
		case IDC_SPRITEHACK:
			return "Helps getting rid of black inner lines in some filtered sprites."
				" Half option is the preferred one. Use it for Mana Khemia or Ar tonelico for example."
				" Full can be used for Tales of Destiny.";
		case IDC_WILDHACK:
			return "Lowers the GS precision to avoid gaps between pixels when upscaling.\n"
				"Fixes the text on Wild Arms games.";
		case IDC_MSAACB:
			return "Enables hardware Anti-Aliasing. Needs lots of memory.\n\n"
				"Note: MSAA often causes graphical glitches.";
		case IDC_ALPHASTENCIL:
			return "Extend stencil based emulation of destination alpha to perform stencil operations while drawing.\n\n"
				"Improves many shadows which are normally overdrawn in parts, may affect other effects.\n"
				"Will disable partial transparency in some games or even prevent drawing some elements altogether.";
		case IDC_ALIGN_SPRITE:
			return "Fixes issues with upscaling(vertical lines) in Namco games like Ace Combat, Tekken, Soul Calibur, etc.";
		case IDC_ROUND_SPRITE:
			return "Corrects the sampling of 2D sprite textures when upscaling.\n\n"
				"Fixes lines in sprites of games like Ar tonelico when upscaling.\n\n"
				"Half option is for flat sprites, Full is for all sprites.";
		case IDC_TCOFFSETX:
		case IDC_TCOFFSETX2:
		case IDC_TCOFFSETY:
		case IDC_TCOFFSETY2:
			return "Offset for the ST/UV texture coordinates. Fixes some odd texture issues and might fix some post processing alignment too.\n\n"
				"  0500 0500, fixes Persona 3 minimap, helps Haunting Ground.";
		case IDC_OSD_LOG:
			return "Prints log messages from the Function keys onscreen.";
		case IDC_OSD_MONITOR:
			return "Continuously prints the FPS and the EE, GS and VU(if the MTVU speedhack is enabled) percentages onscreen.";
		case IDC_PALTEX:
			return "When checked 4/8 bits texture will be send to the GPU with a palette. GPU will be in charge of the conversion.\n\n"
				"When unchecked the CPU will convert directly the texture to 32 bits.\n\n"
				"It is basically a trade-off between GPU/CPU.";
		case IDC_ACCURATE_DATE:
			return "Implement a more accurate algorithm to compute GS destination alpha testing.\n\n"
				"None:\nDisables accurate destination alpha testing.\n\n"
				"Fast:\nFast accurate destination alpha testing.\n"
				"Most of the time this option should be enough.\n"
				"This is the recommended setting.\n\n"
				"Full:\nSlower but fully emulates destination alpha testing.\n"
				"Not needed unless Fast mode isn't enough.\n\n"
				"Note: Full mode is not available on Direct3D.";
		case IDC_ACCURATE_BLEND_UNIT:
			return "Control the accuracy level of the GS blending unit emulation.\n\n"
				"None:\nFast but introduces various rendering issues.\n"
				"It is intended for slow computer.\n\n"
				"Basic:\nEmulate correctly most of the effects with a limited speed penalty.\n"
				"This is the recommended setting.\n\n"
				"Medium:\nExtend it to all sprites. Performance impact remains reasonable in 3D game.\n\n"
				"High:\nExtend it to destination alpha blending and color wrapping (helps shadow and fog effects).\n"
				"A good CPU is required.\n\n"
				"Full:\nExcept few cases, the blending unit will be fully emulated by the shader. It is ultra slow!\n"
				"It is intended for debug.\n\n"
				"Ultra:\nThe blending unit will be completely emulated by the shader. It is ultra slow!\n"
				"It is intended for debug.";
		case IDC_TC_DEPTH:
			return "Disable the support of Depth buffer in the texture cache.\n"
				"It can help to increase speed but it will likely create various glitches.";
		case IDC_CPU_FB_CONVERSION:
			return "Convert 4-bit and 8-bit frame buffer on the CPU instead of the GPU.\n\n"
				"The hack can fix glitches in some games.\n"
				"Harry Potter games and Stuntman for example.\n\n"
				"Note: This hack has an impact on performance.\n";
		case IDC_AFCOMBO:
			return "Reduces texture aliasing at extreme viewing angles. High performance impact.";
		case IDC_AA1:
			return "Internal GS feature. Reduces edge aliasing of lines and triangles when the game requests it.";
		case IDC_SWTHREADS:
		case IDC_SWTHREADS_EDIT:
			return "Number of rendering threads: 0 for single thread, 2 or more for multithread (1 is for debugging)";
		case IDC_MIPMAP_SW:
			return "Enables mipmapping, which some games require to render correctly.";
		case IDC_SHADEBOOST:
			return "Allows brightness, contrast and saturation to be manually adjusted.";
		case IDC_SHADER_FX:
			return "Enables external shader for additional post-processing effects.";
		case IDC_FXAA:
			return "Enables fast approximate anti-aliasing. Small performance impact.";
		case IDC_AUTO_FLUSH:
			return "Force a primitive flush when a framebuffer is also an input texture.\n"
				"Fixes some processing effects such as the shadows in the Jak series and radiosity in GTA:SA.\n"
				"Warning: it's very costly on the performance.\n\n"
				"Note: OpenGL HW renderer is able to handle Jak shadows at full speed without this option.";
		case IDC_SAFE_FEATURES:
			return "This option disables multiple safe features.\n\n"
				"Disables accurate Ucnscale Point and Line rendering.\n"
				"It can help Xenosaga games.\n\n"
				"Disables accurate GS Memory Clearing to be done on the CPU, and let only the GPU hangle it.\n"
				"It can help Kingdom Hearts games.";
		case IDC_MEMORY_WRAPPING:
			return "Emulates GS memory wrapping accurately. This fixes issues where part of the image is cut-off by block shaped sections such as the FMVs in Wallace & Gromit: The Curse of the Were-Rabbit and Thrillville.\n\n"
				"Note: This hack can have a small impact on performance.";
		case IDC_MERGE_PP_SPRITE:
			return "Replaces post-processing multiple paving sprites by a single fat sprite.\n"
				" It reduces various upscaling lines.\n\n"
				"Note: This hack is a work in progress.";
		case IDC_GEOMETRY_SHADER_OVERRIDE:
			return "Allows the GPU instead of just the CPU to transform lines into sprites. This reduces CPU load and bandwidth requirement, but it is heavier on the GPU.\n"
				"Automatic detection is recommended.\n\n"
				"Note: This option is only supported by GPUs which support at least Direct3D 10.";
		case IDC_IMAGE_LOAD_STORE:
			return "Allows advanced atomic operations to speed up Accurate Date.\n"
				"Only disable this if using Accurate Date causes (GPU driver) issues.\n\n"
				"Note: This option is only supported by GPUs which support at least Direct3D 11.";
		case IDC_OSD_MAX_LOG_EDIT:
		case IDC_OSD_MAX_LOG:
			return "Sets the maximum number of log messages on the screen or in the buffer at the same time.\n\n"
				"The maximum number of messages visible on the screen at the same time also depends on the character size.";
		case IDC_LINEAR_PRESENT:
			return "Use bilinear filtering when Upscaling/Downscaling the image to the screen. Disable it if you want a sharper/pixelated output.";
		// Exclusive for Hardware Renderer
		case IDC_PRELOAD_GS:
			return "Uploads GS data when rendering a new frame to reproduce some effects accurately.\n"
				"Fixes black screen issues in games like Armored Core: Last Raven.";
		case IDC_MIPMAP_HW:
			return	"Control the accuracy level of the mipmapping emulation.\n\n"
				"Automatic:\nAutomatically sets the mipmapping level based on the game.\n"
				"This is the recommended setting.\n\n"
				"Off:\nMipmapping emulation is disabled.\n\n"
				"Basic (Fast):\nPartially emulates mipmapping, performance impact is negligible in most cases.\n\n"
				"Full (Slow):\nCompletely emulates the mipmapping function of the GS, might significantly impact performance.";
		case IDC_FAST_TC_INV:
			return "By default, the texture cache handles partial invalidations. Unfortunately it is very costly to compute CPU wise."
				"\n\nThis hack replaces the partial invalidation with a complete deletion of the texture to reduce the CPU load.\n\nIt helps snowblind engine games.";
		case IDC_LARGE_FB:
			return "Allocate a large framebuffer to be compliant with GS memory (Prevents FMV flickering).\n"
				"It increases GPU/memory requirements.\n\n"
				"Note: It should be disabled for Armored Core, Destroy All Humans, and Gran Turismo.\n"
				"It will amplify RAM/VRAM spikes. Other games might be affected as well.";
		default:
			if (updateText)
				*updateText = false;
			return "";
	}
}
