/*
This file was produced by 3D Exploration Plugin: CPP Export filter.

3D Exploration

Copyright (c) 1999-2000 X Dimension Software

WWW         http://www.xdsoft.com/explorer/
eMail       info@xdsoft.com
*/
#include <windows.h>
#include <GL\gl.h>
#include <GL\glu.h>

// 41 Verticies
// 234 Texture Coordinates
// 234 Normals
// 78 Triangles

static GLint face_indicies[78][9] = {
// default
	{10,0,3 ,0,1,2 ,0,1,2 }, {16,13,12 ,3,4,5 ,3,4,5 }, {15,14,19 ,6,7,8 ,6,7,8 },
	{13,16,22 ,9,10,11 ,9,10,11 }, {24,6,1 ,12,13,14 ,12,13,14 },
	{8,2,7 ,15,16,17 ,15,16,17 }, {5,24,1 ,18,19,20 ,18,19,20 },
	{29,19,14 ,21,22,23 ,21,22,23 }, {0,1,2 ,24,25,26 ,24,25,26 },
	{2,3,0 ,27,28,29 ,27,28,29 }, {1,0,4 ,30,31,32 ,30,31,32 }, {4,5,1 ,33,34,35 ,33,34,35 },
	{1,6,7 ,36,37,38 ,36,37,38 }, {7,2,1 ,39,40,41 ,39,40,41 }, {8,9,3 ,42,43,44 ,42,43,44 },
	{3,2,8 ,45,46,47 ,45,46,47 }, {11,4,0 ,48,49,50 ,48,49,50 },
	{0,10,11 ,51,52,53 ,51,52,53 }, {3,9,11 ,54,55,56 ,54,55,56 },
	{11,10,3 ,57,58,59 ,57,58,59 }, {12,13,14 ,60,61,62 ,60,61,62 },
	{14,15,12 ,63,64,65 ,63,64,65 }, {13,17,18 ,66,67,68 ,66,67,68 },
	{18,14,13 ,69,70,71 ,69,70,71 }, {15,20,21 ,72,73,74 ,72,73,74 },
	{21,12,15 ,75,76,77 ,75,76,77 }, {23,16,12 ,78,79,80 ,78,79,80 },
	{12,21,23 ,81,82,83 ,81,82,83 }, {6,25,26 ,84,85,86 ,84,85,86 },
	{26,7,6 ,87,88,89 ,87,88,89 }, {24,27,25 ,90,91,92 ,90,91,92 },
	{25,6,24 ,93,94,95 ,93,94,95 }, {19,28,20 ,96,97,98 ,96,97,98 },
	{20,15,19 ,99,100,101 ,99,100,101 }, {19,29,30 ,102,103,104 ,102,103,104 },
	{30,28,19 ,105,106,107 ,105,106,107 }, {28,31,26 ,108,109,110 ,108,109,110 },
	{26,20,28 ,111,112,113 ,111,112,113 }, {28,30,32 ,114,115,116 ,114,115,116 },
	{32,31,28 ,117,118,119 ,117,118,119 }, {31,8,7 ,120,121,122 ,120,121,122 },
	{7,26,31 ,123,124,125 ,123,124,125 }, {25,21,20 ,126,127,128 ,126,127,128 },
	{20,26,25 ,129,130,131 ,129,130,131 }, {31,32,9 ,132,133,134 ,132,133,134 },
	{9,8,31 ,135,136,137 ,135,136,137 }, {24,5,33 ,138,139,140 ,138,139,140 },
	{33,27,24 ,141,142,143 ,141,142,143 }, {27,23,21 ,144,145,146 ,144,145,146 },
	{21,25,27 ,147,148,149 ,147,148,149 }, {27,33,34 ,150,151,152 ,150,151,152 },
	{34,23,27 ,153,154,155 ,153,154,155 }, {23,34,22 ,156,157,158 ,156,157,158 },
	{22,16,23 ,159,160,161 ,159,160,161 }, {22,35,17 ,162,163,164 ,162,163,164 },
	{17,13,22 ,165,166,167 ,165,166,167 }, {35,36,18 ,168,169,170 ,168,169,170 },
	{18,17,35 ,171,172,173 ,171,172,173 }, {14,18,36 ,174,175,176 ,174,175,176 },
	{36,29,14 ,177,178,179 ,177,178,179 }, {32,37,11 ,180,181,182 ,180,181,182 },
	{11,9,32 ,183,184,185 ,183,184,185 }, {37,38,4 ,186,187,188 ,186,187,188 },
	{4,11,37 ,189,190,191 ,189,190,191 }, {38,37,39 ,192,193,194 ,192,193,194 },
	{39,40,38 ,195,196,197 ,195,196,197 }, {30,39,37 ,198,199,200 ,198,199,200 },
	{37,32,30 ,201,202,203 ,201,202,203 }, {40,39,36 ,204,205,206 ,204,205,206 },
	{36,35,40 ,207,208,209 ,207,208,209 }, {33,38,40 ,210,211,212 ,210,211,212 },
	{40,34,33 ,213,214,215 ,213,214,215 }, {5,4,38 ,216,217,218 ,216,217,218 },
	{38,33,5 ,219,220,221 ,219,220,221 }, {29,36,39 ,222,223,224 ,222,223,224 },
	{39,30,29 ,225,226,227 ,225,226,227 }, {34,40,35 ,228,229,230 ,228,229,230 },
	{35,22,34 ,231,232,233 ,231,232,233 }
};
static GLfloat vertices [41][3] = {
{0.55845f,-0.248099f,0.1181f},{0.59155f,-0.2221f,0.0871004f},{0.59605f,-0.215f,0.0916005f},
{0.56365f,-0.2384f,0.117599f},{0.53205f,-0.231f,0.114703f},{0.53905f,-0.2035f,0.0847045f},
{0.58415f,-0.1461f,0.0379024f},{0.58905f,-0.1421f,0.0427005f},{0.57175f,-0.1703f,0.0779985f},
{0.54495f,-0.2035f,0.110799f},{0.55655f,-0.2502f,0.121903f},{0.52635f,-0.2374f,0.1262f},
{-0.28375f,0.1427f,-0.0931975f},{-0.59605f,-0.055f,0.0171005f},{-0.59565f,-0.0532f,0.0294025f},
{-0.27335f,0.1711f,-0.0827015f},{-0.28845f,0.1127f,-0.0326994f},{-0.52055f,-0.039f,0.0416035f},
{-0.51715f,-0.0414f,0.0461046f},{-0.27765f,0.146f,-0.0315015f},{0.03865f,0.2502f,-0.1194f},
{0.03765f,0.2163f,-0.1262f},{-0.29615f,0.0573f,-0.00190148f},{0.02635f,0.1825f,-0.0741955f},
{0.55395f,-0.1871f,0.0760015f},{0.28815f,0.148501f,-0.0997005f},{0.27855f,0.1836f,-0.0919995f},
{0.25465f,0.1166f,-0.0405015f},{0.03035f,0.218301f,-0.0671985f},{-0.28825f,0.0868f,0.0223046f},
{0.01875f,0.156301f,-0.0147995f},{0.25485f,0.1572f,-0.0360965f},{0.23435f,0.099801f,0.0102994f},
{0.24025f,0.0857f,-0.00609757f},{0.02345f,0.1426f,-0.0324964f},{-0.30885f,0.0501f,0.0322995f},
{-0.29865f,0.0429f,0.0456035f},{0.21355f,0.0574f,0.0333015f},{0.22405f,0.0623f,0.0150025f},
{0.00995f,0.1114f,0.00920248f},{0.00905f,0.1172f,-0.00820148f}
};
static GLfloat normals [234][3] = {
{0.870453f,-0.457265f,0.182266f},{0.796512f,-0.493651f,0.34911f},{0.819014f,-0.418844f,0.392155f},
{0.269422f,-0.870936f,-0.410952f},{0.282388f,-0.843421f,-0.457054f},{0.226778f,-0.864642f,-0.448293f},
{-0.312765f,0.862979f,0.396795f},{-0.378634f,0.750304f,0.541923f},{-0.202251f,0.780749f,0.591208f},
{0.282388f,-0.843421f,-0.457054f},{0.0618735f,-0.491511f,-0.868671f},{0.0845712f,-0.574064f,-0.814431f},
{-0.249865f,-0.542116f,-0.802295f},{-0.239362f,-0.560442f,-0.79285f},{-0.216146f,-0.557775f,-0.801354f},
{0.410588f,0.506553f,0.75817f},{0.451231f,0.475161f,0.755389f},{0.480142f,0.606692f,0.633553f},
{-0.218957f,-0.540072f,-0.812638f},{-0.249865f,-0.542116f,-0.802295f},{-0.216146f,-0.557775f,-0.801354f},
{-0.114019f,0.565601f,0.816759f},{-0.202251f,0.780749f,0.591208f},{-0.378634f,0.750304f,0.541923f},
{0.796512f,-0.493651f,0.34911f},{0.734268f,-0.628306f,0.257064f},{0.748049f,-0.50567f,0.429792f},
{0.748049f,-0.50567f,0.429792f},{0.819014f,-0.418844f,0.392155f},{0.796512f,-0.493651f,0.34911f},
{-0.216146f,-0.557775f,-0.801354f},{-0.350336f,-0.671057f,-0.653411f},{-0.374799f,-0.671331f,-0.639406f},
{-0.374799f,-0.671331f,-0.639406f},{-0.218957f,-0.540072f,-0.812638f},{-0.216146f,-0.557775f,-0.801354f},
{0.815022f,-0.261501f,-0.517065f},{0.699754f,0.094706f,-0.708078f},{0.768315f,-0.102143f,-0.631869f},
{0.768315f,-0.102143f,-0.631869f},{0.847907f,-0.236761f,-0.47434f},{0.815022f,-0.261501f,-0.517065f},
{0.410588f,0.506553f,0.75817f},{0.267406f,0.44142f,0.856529f},{0.318363f,0.342561f,0.88391f},
{0.318363f,0.342561f,0.88391f},{0.451231f,0.475161f,0.755389f},{0.410588f,0.506553f,0.75817f},
{-0.407593f,-0.69723f,-0.589693f},{-0.374799f,-0.671331f,-0.639406f},{-0.350336f,-0.671057f,-0.653411f},
{-0.350336f,-0.671057f,-0.653411f},{-0.385433f,-0.71258f,-0.586235f},{-0.407593f,-0.69723f,-0.589693f},
{0.318363f,0.342561f,0.88391f},{0.267406f,0.44142f,0.856529f},{0.163531f,0.330034f,0.929696f},
{0.163531f,0.330034f,0.929696f},{0.224992f,0.211545f,0.951119f},{0.318363f,0.342561f,0.88391f},
{-0.557634f,0.823747f,-0.102397f},{-0.557634f,0.823747f,-0.102397f},{-0.378634f,0.750304f,0.541923f},
{-0.559763f,0.459772f,-0.689402f},{-0.311902f,0.363534f,-0.877816f},{-0.380805f,0.44001f,-0.813252f},
{0.282388f,-0.843421f,-0.457054f},{0.343304f,-0.83514f,-0.429749f},{0.306535f,-0.722433f,-0.619779f},
{0.117989f,-0.983095f,0.140007f},{0.117989f,-0.983095f,0.140007f},{0.282388f,-0.843421f,-0.457054f},
{-0.311902f,0.363534f,-0.877816f},{0.0573662f,0.218169f,-0.974223f},{-0.0657033f,0.26725f,-0.961385f},
{-0.0657033f,0.26725f,-0.961385f},{-0.380805f,0.44001f,-0.813252f},{-0.311902f,0.363534f,-0.877816f},
{0.0246799f,-0.765203f,-0.643316f},{0.269422f,-0.870936f,-0.410952f},{0.226778f,-0.864642f,-0.448293f},
{0.226778f,-0.864642f,-0.448293f},{-0.0600402f,-0.836175f,-0.545166f},{0.0246799f,-0.765203f,-0.643316f},
{0.699754f,0.094706f,-0.708078f},{0.339053f,0.268141f,-0.901744f},{0.48226f,0.279309f,-0.830308f},
{0.48226f,0.279309f,-0.830308f},{0.768315f,-0.102143f,-0.631869f},{0.699754f,0.094706f,-0.708078f},
{-0.249865f,-0.542116f,-0.802295f},{-0.222727f,-0.735376f,-0.640011f},{-0.276251f,-0.702112f,-0.656296f},
{-0.276251f,-0.702112f,-0.656296f},{-0.239362f,-0.560442f,-0.79285f},{-0.249865f,-0.542116f,-0.802295f},
{-0.202251f,0.780749f,0.591208f},{0.0451305f,0.757546f,0.65122f},{-0.0505257f,0.869465f,0.491404f},
{-0.0505257f,0.869465f,0.491404f},{-0.312765f,0.862979f,0.396795f},{-0.202251f,0.780749f,0.591208f},
{-0.202251f,0.780749f,0.591208f},{-0.114019f,0.565601f,0.816759f},{-0.00225661f,0.566554f,0.824021f},
{-0.00225661f,0.566554f,0.824021f},{0.0451305f,0.757546f,0.65122f},{-0.202251f,0.780749f,0.591208f},
{0.0451305f,0.757546f,0.65122f},{0.28452f,0.661584f,0.693797f},{0.280318f,0.805055f,0.522788f},
{0.280318f,0.805055f,0.522788f},{-0.0505257f,0.869465f,0.491404f},{0.0451305f,0.757546f,0.65122f},
{0.0451305f,0.757546f,0.65122f},{-0.00225661f,0.566554f,0.824021f},{0.106547f,0.515736f,0.850097f},
{0.106547f,0.515736f,0.850097f},{0.28452f,0.661584f,0.693797f},{0.0451305f,0.757546f,0.65122f},
{0.28452f,0.661584f,0.693797f},{0.410588f,0.506553f,0.75817f},{0.480142f,0.606692f,0.633553f},
{0.480142f,0.606692f,0.633553f},{0.280318f,0.805055f,0.522788f},{0.28452f,0.661584f,0.693797f},
{0.339053f,0.268141f,-0.901744f},{-0.0657033f,0.26725f,-0.961385f},{0.0573662f,0.218169f,-0.974223f},
{0.0573662f,0.218169f,-0.974223f},{0.48226f,0.279309f,-0.830308f},{0.339053f,0.268141f,-0.901744f},
{0.28452f,0.661584f,0.693797f},{0.106547f,0.515736f,0.850097f},{0.267406f,0.44142f,0.856529f},
{0.267406f,0.44142f,0.856529f},{0.410588f,0.506553f,0.75817f},{0.28452f,0.661584f,0.693797f},
{-0.249865f,-0.542116f,-0.802295f},{-0.218957f,-0.540072f,-0.812638f},{-0.168385f,-0.602078f,-0.78048f},
{-0.168385f,-0.602078f,-0.78048f},{-0.222727f,-0.735376f,-0.640011f},{-0.249865f,-0.542116f,-0.802295f},
{-0.222727f,-0.735376f,-0.640011f},{0.0246799f,-0.765203f,-0.643316f},{-0.0600402f,-0.836175f,-0.545166f},
{-0.0600402f,-0.836175f,-0.545166f},{-0.276251f,-0.702112f,-0.656296f},{-0.222727f,-0.735376f,-0.640011f},
{-0.222727f,-0.735376f,-0.640011f},{-0.168385f,-0.602078f,-0.78048f},{-0.021249f,-0.70858f,-0.70531f},
{-0.021249f,-0.70858f,-0.70531f},{0.0246799f,-0.765203f,-0.643316f},{-0.222727f,-0.735376f,-0.640011f},
{0.0246799f,-0.765203f,-0.643316f},{-0.021249f,-0.70858f,-0.70531f},{0.0845712f,-0.574064f,-0.814431f},
{0.0845712f,-0.574064f,-0.814431f},{0.0618735f,-0.491511f,-0.868671f},{0.0246799f,-0.765203f,-0.643316f},
{0.316172f,-0.931707f,-0.178765f},{0.238602f,-0.856057f,-0.458515f},{0.343304f,-0.83514f,-0.429749f},
{0.343304f,-0.83514f,-0.429749f},{0.282388f,-0.843421f,-0.457054f},{0.316172f,-0.931707f,-0.178765f},
{0.238602f,-0.856057f,-0.458515f},{0.189349f,-0.846818f,-0.497037f},{0.306535f,-0.722433f,-0.619779f},
{0.306535f,-0.722433f,-0.619779f},{0.343304f,-0.83514f,-0.429749f},{0.238602f,-0.856057f,-0.458515f},
{-0.378634f,0.750304f,0.541923f},{-0.250251f,0.652884f,0.714924f},{-0.154077f,0.545854f,0.823592f},
{-0.154077f,0.545854f,0.823592f},{-0.114019f,0.565601f,0.816759f},{-0.378634f,0.750304f,0.541923f},
{0.106547f,0.515736f,0.850097f},{0.0571739f,0.453928f,0.889202f},{0.163531f,0.330034f,0.929696f},
{0.163531f,0.330034f,0.929696f},{0.267406f,0.44142f,0.856529f},{0.106547f,0.515736f,0.850097f},
{-0.396607f,-0.77687f,-0.489057f},{-0.288205f,-0.756162f,-0.5875f},{-0.374799f,-0.671331f,-0.639406f},
{-0.374799f,-0.671331f,-0.639406f},{-0.407593f,-0.69723f,-0.589693f},{-0.396607f,-0.77687f,-0.489057f},
{-0.288205f,-0.756162f,-0.5875f},{-0.396607f,-0.77687f,-0.489057f},{-0.0798198f,-0.940173f,-0.331215f},
{-0.0798198f,-0.940173f,-0.331215f},{-0.00546765f,-0.813156f,-0.582021f},{-0.288205f,-0.756162f,-0.5875f},
{-0.00225661f,0.566554f,0.824021f},{0.00655192f,0.469538f,0.882888f},{0.0571739f,0.453928f,0.889202f},
{0.0571739f,0.453928f,0.889202f},{0.106547f,0.515736f,0.850097f},{-0.00225661f,0.566554f,0.824021f},
{-0.00546765f,-0.813156f,-0.582021f},{-0.0798198f,-0.940173f,-0.331215f},{0.189349f,-0.846818f,-0.497037f},
{0.189349f,-0.846818f,-0.497037f},{0.238602f,-0.856057f,-0.458515f},{-0.00546765f,-0.813156f,-0.582021f},
{-0.168385f,-0.602078f,-0.78048f},{-0.288205f,-0.756162f,-0.5875f},{-0.00546765f,-0.813156f,-0.582021f},
{-0.00546765f,-0.813156f,-0.582021f},{-0.021249f,-0.70858f,-0.70531f},{-0.168385f,-0.602078f,-0.78048f},
{-0.218957f,-0.540072f,-0.812638f},{-0.374799f,-0.671331f,-0.639406f},{-0.288205f,-0.756162f,-0.5875f},
{-0.288205f,-0.756162f,-0.5875f},{-0.168385f,-0.602078f,-0.78048f},{-0.218957f,-0.540072f,-0.812638f},
{-0.114019f,0.565601f,0.816759f},{-0.154077f,0.545854f,0.823592f},{0.00655192f,0.469538f,0.882888f},
{0.00655192f,0.469538f,0.882888f},{-0.00225661f,0.566554f,0.824021f},{-0.114019f,0.565601f,0.816759f},
{-0.021249f,-0.70858f,-0.70531f},{-0.00546765f,-0.813156f,-0.582021f},{0.238602f,-0.856057f,-0.458515f},
{0.238602f,-0.856057f,-0.458515f},{0.316172f,-0.931707f,-0.178765f},{0.246317f,-0.962787f,-0.11122f}
};
static GLfloat textures [234][2] = {
{0.033135f,0.017026f},{0.031541f,0.032093f},{0.027179f,0.034076f},
{0.741968f,0.629552f},{1.0f,0.432249f},{0.738025f,0.869244f},
{0.729301f,0.827658f},{0.999664f,0.383507f},{0.732908f,0.624805f},
{1.0f,0.432249f},{0.741968f,0.629552f},{0.748427f,0.507533f},
{0.035316f,0.198885f},{0.009982f,0.349832f},{0.003775f,0.154914f},
{0.020384f,0.190974f},{0.0f,0.137085f},{0.005872f,0.330822f},
{0.047815f,0.164407f},{0.035316f,0.198885f},{0.003775f,0.154914f},
{0.7418f,0.411633f},{0.732908f,0.624805f},{0.999664f,0.383507f},
{0.031541f,0.032093f},{0.003775f,0.154914f},{0.0f,0.137085f},
{0.0f,0.137085f},{0.027179f,0.034076f},{0.031541f,0.032093f},
{0.003775f,0.154914f},{0.031541f,0.032093f},{0.053687f,0.045553f},
{0.053687f,0.045553f},{0.047815f,0.164407f},{0.003775f,0.154914f},
{0.003775f,0.154914f},{0.009982f,0.349832f},{0.005872f,0.330822f},
{0.005872f,0.330822f},{0.0f,0.137085f},{0.003775f,0.154914f},
{0.020384f,0.190974f},{0.042866f,0.061021f},{0.027179f,0.034076f},
{0.027179f,0.034076f},{0.0f,0.137085f},{0.020384f,0.190974f},
{0.058468f,0.0f},{0.053687f,0.045553f},{0.031541f,0.032093f},
{0.031541f,0.032093f},{0.033135f,0.017026f},{0.058468f,0.0f},
{0.027179f,0.034076f},{0.042866f,0.061021f},{0.058468f,0.0f},
{0.058468f,0.0f},{0.033135f,0.017026f},{0.027179f,0.034076f},
{0.738025f,0.869244f},{1.0f,0.432249f},{0.999664f,0.383507f},
{0.999664f,0.383507f},{0.729301f,0.827658f},{0.738025f,0.869244f},
{1.0f,0.432249f},{0.936666f,0.335167f},{0.933814f,0.317338f},
{0.933814f,0.317338f},{0.999664f,0.383507f},{1.0f,0.432249f},
{0.729301f,0.827658f},{0.467578f,0.973055f},{0.468417f,1.0f},
{0.468417f,1.0f},{0.738025f,0.869244f},{0.729301f,0.827658f},
{0.477896f,0.793959f},{0.741968f,0.629552f},{0.738025f,0.869244f},
{0.738025f,0.869244f},{0.468417f,1.0f},{0.477896f,0.793959f},
{0.009982f,0.349832f},{0.258284f,0.895008f},{0.266337f,0.864497f},
{0.266337f,0.864497f},{0.005872f,0.330822f},{0.009982f,0.349832f},
{0.035316f,0.198885f},{0.286385f,0.660464f},{0.258284f,0.895008f},
{0.258284f,0.895008f},{0.009982f,0.349832f},{0.035316f,0.198885f},
{0.732908f,0.624805f},{0.474541f,0.766235f},{0.467578f,0.973055f},
{0.467578f,0.973055f},{0.729301f,0.827658f},{0.732908f,0.624805f},
{0.732908f,0.624805f},{0.7418f,0.411633f},{0.484271f,0.558636f},
{0.484271f,0.558636f},{0.474541f,0.766235f},{0.732908f,0.624805f},
{0.474541f,0.766235f},{0.286218f,0.643012f},{0.266337f,0.864497f},
{0.266337f,0.864497f},{0.467578f,0.973055f},{0.474541f,0.766235f},
{0.474541f,0.766235f},{0.484271f,0.558636f},{0.303414f,0.459193f},
{0.303414f,0.459193f},{0.286218f,0.643012f},{0.474541f,0.766235f},
{0.286218f,0.643012f},{0.020384f,0.190974f},{0.005872f,0.330822f},
{0.005872f,0.330822f},{0.266337f,0.864497f},{0.286218f,0.643012f},
{0.258284f,0.895008f},{0.468417f,1.0f},{0.467578f,0.973055f},
{0.467578f,0.973055f},{0.266337f,0.864497f},{0.258284f,0.895008f},
{0.286218f,0.643012f},{0.303414f,0.459193f},{0.042866f,0.061021f},
{0.042866f,0.061021f},{0.020384f,0.190974f},{0.286218f,0.643012f},
{0.035316f,0.198885f},{0.047815f,0.164407f},{0.298465f,0.524158f},
{0.298465f,0.524158f},{0.286385f,0.660464f},{0.035316f,0.198885f},
{0.286385f,0.660464f},{0.477896f,0.793959f},{0.468417f,1.0f},
{0.468417f,1.0f},{0.258284f,0.895008f},{0.286385f,0.660464f},
{0.286385f,0.660464f},{0.298465f,0.524158f},{0.480329f,0.628749f},
{0.480329f,0.628749f},{0.477896f,0.793959f},{0.286385f,0.660464f},
{0.477896f,0.793959f},{0.480329f,0.628749f},{0.748427f,0.507533f},
{0.748427f,0.507533f},{0.741968f,0.629552f},{0.477896f,0.793959f},
{0.748427f,0.507533f},{0.759081f,0.37203f},{0.936666f,0.335167f},
{0.936666f,0.335167f},{1.0f,0.432249f},{0.748427f,0.507533f},
{0.759081f,0.37203f},{0.750524f,0.319322f},{0.933814f,0.317338f},
{0.933814f,0.317338f},{0.936666f,0.335167f},{0.759081f,0.37203f},
{0.999664f,0.383507f},{0.933814f,0.317338f},{0.750524f,0.319322f},
{0.750524f,0.319322f},{0.7418f,0.411633f},{0.999664f,0.383507f},
{0.303414f,0.459193f},{0.320862f,0.368063f},{0.058468f,0.0f},
{0.058468f,0.0f},{0.042866f,0.061021f},{0.303414f,0.459193f},
{0.320862f,0.368063f},{0.312054f,0.440561f},{0.053687f,0.045553f},
{0.053687f,0.045553f},{0.058468f,0.0f},{0.320862f,0.368063f},
{0.312054f,0.440561f},{0.320862f,0.368063f},{0.491653f,0.463538f},
{0.491653f,0.463538f},{0.492408f,0.532494f},{0.312054f,0.440561f},
{0.484271f,0.558636f},{0.491653f,0.463538f},{0.320862f,0.368063f},
{0.320862f,0.368063f},{0.303414f,0.459193f},{0.484271f,0.558636f},
{0.492408f,0.532494f},{0.491653f,0.463538f},{0.750524f,0.319322f},
{0.750524f,0.319322f},{0.759081f,0.37203f},{0.492408f,0.532494f},
{0.298465f,0.524158f},{0.312054f,0.440561f},{0.492408f,0.532494f},
{0.492408f,0.532494f},{0.480329f,0.628749f},{0.298465f,0.524158f},
{0.047815f,0.164407f},{0.053687f,0.045553f},{0.312054f,0.440561f},
{0.312054f,0.440561f},{0.298465f,0.524158f},{0.047815f,0.164407f},
{0.7418f,0.411633f},{0.750524f,0.319322f},{0.491653f,0.463538f},
{0.491653f,0.463538f},{0.484271f,0.558636f},{0.7418f,0.411633f},
{0.480329f,0.628749f},{0.492408f,0.532494f},{0.759081f,0.37203f},
{0.759081f,0.37203f},{0.748427f,0.507533f},{0.480329f,0.628749f}
};

GLint Gen_Inf_lashes()
{
 int i;
 int j;

 GLint lid=glGenLists(1);
  glNewList(lid, GL_COMPILE);

    glBegin (GL_TRIANGLES);
      for(i=0;i<sizeof(face_indicies)/sizeof(face_indicies[0]);i++)
       {
       for(j=0;j<3;j++)
        {
          int vi=face_indicies[i][j];
          int ni=face_indicies[i][j+3];//Normal index
          int ti=face_indicies[i][j+6];//Texture index
           glNormal3f (normals[ni][0],normals[ni][1],normals[ni][2]);
           glTexCoord2f(textures[ti][0],textures[ti][1]);
           glVertex3f (vertices[vi][0],vertices[vi][1],vertices[vi][2]);
        }
       }
    glEnd ();

   glEndList();
   return lid;
};

GLint Gen_Sim_Inf_lashes()
{
 int i;
 int j;

 GLint lid=glGenLists(1);
  glNewList(lid, GL_COMPILE);

    glBegin (GL_TRIANGLES);
      for(i=0;i<sizeof(face_indicies)/sizeof(face_indicies[0]);i++)
       {
       for(j=0;j<3;j++)
        {
          int vi=face_indicies[i][j];
          int ni=face_indicies[i][j+3];//Normal index
          int ti=face_indicies[i][j+6];//Texture index
           glNormal3f (normals[ni][0],normals[ni][1],normals[ni][2]);
           glTexCoord2f(-textures[ti][0],textures[ti][1]);
           glVertex3f (-vertices[vi][0],vertices[vi][1],vertices[vi][2]);
        }
       }
    glEnd ();

   glEndList();
   return lid;
};