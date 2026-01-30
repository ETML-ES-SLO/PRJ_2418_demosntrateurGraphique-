/* 
 * File:   FT_GPU.h
 * Author: roestilo
 *
 * Created on 19. août 2014, 13:35
 */

#ifndef FT_GPU_H
#define	FT_GPU_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Definitions used for FT800 co processor command buffer */
#define FT_DL_SIZE           (8*1024)  //8KB Display List buffer size
#define FT_CMD_FIFO_SIZE     (4*1024)  //4KB coprocessor Fifo size
#define FT_CMD_SIZE          (4)       //4 byte per coprocessor command of EVE

#define FT800_VERSION "1.9.0"
#define ADC_DIFFERENTIAL     1UL
#define ADC_SINGLE_ENDED     0UL
#define ADPCM_SAMPLES        2UL
#define ALWAYS               7UL
#define ARGB1555             0UL
#define ARGB2                5UL
#define ARGB4                6UL
#define BARGRAPH             11UL
#define BILINEAR             1UL
#define BORDER               0UL

// section 4.2
#define BITMAPS              1UL
#define POINTS               2UL
#define LINES               3UL
#define LINE_STRIP          4UL
#define EDGE_R              5UL
#define EDGE_L              6UL
#define EDGE_A              7UL
#define EDGE_B              8UL
#define RECTS               9UL

//#define CMDBUF_SIZE          4096UL
#define CMD_APPEND           0xFFFFFF1E//4294967070UL
#define CMD_BGCOLOR          0xFFFFFF09//4294967049UL
#define CMD_BITMAP_TRANSFORM 0xFFFFFF21//4294967073UL
#define CMD_BUTTON           0xFFFFFF0D//4294967053UL
#define CMD_CALIBRATE        0xFFFFFF15//4294967061UL
#define CMD_CLOCK            0xFFFFFF14//4294967060UL
#define CMD_COLDSTART        0xFFFFFF32//4294967090UL
//#define CMD_CRC              4294967043UL
#define CMD_DIAL             0xFFFFFF2D//4294967085UL
#define CMD_DLSTART          0xFFFFFF00//4294967040UL
#define CMD_DLSWAP           0xFFFFFF1E//4294967041UL
//#define CMD_EXECUTE          4294967047UL
#define CMD_FGCOLOR          0xFFFFFF0A//4294967050UL
#define CMD_GAUGE            0xFFFFFF13//4294967059UL
#define CMD_GETMATRIX        0xFFFFFF33//4294967091UL
//#define CMD_GETPOINT         4294967048UL
#define CMD_GETPROPS         0xFFFFFF25//4294967077UL
#define CMD_GETPTR           0xFFFFFF23//4294967075UL
#define CMD_GRADCOLOR        0xFFFFFF34//4294967092UL
#define CMD_GRADIENT         0xFFFFFF0B//4294967051UL
//#define CMD_HAMMERAUX        4294967044UL
//#define CMD_IDCT             4294967046UL
#define CMD_INFLATE          0xFFFFFF22//4294967074UL
#define CMD_INTERRUPT        0xFFFFFF02//4294967042UL
#define CMD_KEYS             0xFFFFFF0E//4294967054UL
#define CMD_LOADIDENTITY     0xFFFFFF26//4294967078UL
#define CMD_LOADIMAGE        0xFFFFFF24//4294967076UL
#define CMD_LOGO             0xFFFFFF31//4294967089UL
//#define CMD_MARCH            4294967045UL
#define CMD_MEMCPY           0xFFFFFF1D//4294967069UL
#define CMD_MEMCRC           0xFFFFFF18//4294967064UL
#define CMD_MEMSET           0xFFFFFF1B//4294967067UL
#define CMD_MEMWRITE         0xFFFFFF1A//4294967066UL
#define CMD_MEMZERO          0xFFFFFF1C//4294967068UL
#define CMD_NUMBER           0xFFFFFF2E//4294967086UL
#define CMD_PROGRESS         0xFFFFFF0F//4294967055UL
#define CMD_REGREAD          0xFFFFFF19//4294967065UL
#define CMD_ROTATE           0xFFFFFF29//4294967081UL
#define CMD_SCALE            0xFFFFFF28//4294967080UL
#define CMD_SCREENSAVER      0xFFFFFF2F//4294967087UL
#define CMD_SCROLLBAR        0xFFFFFF11//4294967057UL
#define CMD_SETFONT          0xFFFFFF2B//4294967083UL
#define CMD_SETMATRIX        0xFFFFFF2A//4294967082UL
#define CMD_SKETCH           0xFFFFFF30//4294967088UL
#define CMD_SLIDER           0xFFFFFF10//4294967056UL
#define CMD_SNAPSHOT         0xFFFFFF1F//4294967071UL
#define CMD_SPINNER          0xFFFFFF16//4294967062UL
#define CMD_STOP             0xFFFFFF17//4294967063UL
#define CMD_SWAP             0xFFFFFF01//4294967041UL
#define CMD_TEXT             0xFFFFFF0C//4294967052UL
#define CMD_TOGGLE           0xFFFFFF12//4294967058UL
//#define CMD_TOUCH_TRANSFORM  4294967072UL
#define CMD_TRACK            0xFFFFFF2C//4294967084UL
#define CMD_TRANSLATE        0xFFFFFF27//4294967079UL

#define DECR                 4UL
#define DECR_WRAP            7UL
#define DLSWAP_DONE          0UL
#define DLSWAP_FRAME         2UL
#define DLSWAP_LINE          1UL
#define DST_ALPHA            3UL
#define EQUAL                5UL
#define GEQUAL               4UL
#define GREATER              3UL
#define INCR                 3UL
#define INCR_WRAP            6UL
#define INT_CMDEMPTY         32UL
#define INT_CMDFLAG          64UL
#define INT_CONVCOMPLETE     128UL
#define INT_PLAYBACK         16UL
#define INT_SOUND            8UL
#define INT_SWAP             1UL
#define INT_TAG              4UL
#define INT_TOUCH            2UL
#define INVERT               5UL

#define KEEP                 1UL
#define L1                   1UL
#define L4                   2UL
#define L8                   3UL
#define LEQUAL               2UL
#define LESS                 1UL
#define LINEAR_SAMPLES       0UL
#define NEAREST              0UL
#define NEVER                0UL
#define NOTEQUAL             6UL
#define ONE                  1UL
#define ONE_MINUS_DST_ALPHA  5UL
#define ONE_MINUS_SRC_ALPHA  4UL
#define OPT_CENTER           1536UL
#define OPT_CENTERX          512UL
#define OPT_CENTERY          1024UL
#define OPT_FLAT             256UL
#define OPT_MONO             1UL
#define OPT_NOBACK           4096UL
#define OPT_NODL             2UL
#define OPT_NOHANDS          49152UL
#define OPT_NOHM             16384UL
#define OPT_NOPOINTER        16384UL
#define OPT_NOSECS           32768UL
#define OPT_NOTICKS          8192UL
#define OPT_RIGHTX           2048UL
#define OPT_SIGNED           256UL
#define PALETTED             8UL

#define RAM_G                0x000000
#define ROM_FONT             0x1E0000//766524UL
#define ROM_FONT_ADDR        0x2FFFFC//1048572UL
#define RAM_DL               0x300000//1048576UL
#define RAM_REG              0x302000//1057792UL
#define RAM_CMD              0x308000//1081344UL

#define REG_ANA_COMP         0x302184//1058160UL
#define REG_CLOCK            0x302008 //1057800UL
#define REG_CMD_DL           0x302100//1058028UL
#define REG_CMD_READ         0x3020F8//1058020UL
#define REG_CMD_WRITE        0x3020FC//1058024UL
    
#define REG_CPURESET         0x302020//1057820UL
#define REG_DATESTAMP        0x302564//1058108UL
#define REG_FRAMES           0x302004 //1057796UL
#define REG_FREQUENCY        0x30200C //1057804UL
#define REG_GPIO             0x302094//1057936UL
#define REG_GPIO_DIR         0x302090//1057932UL

#define REG_HCYCLE           0x30202C//1057832UL
#define REG_HOFFSET          0x302030//1057836UL
#define REG_HSIZE            0x302034//1057840UL
#define REG_HSYNC0           0x302038//1057844UL
#define REG_HSYNC1           0x30203C//1057848UL
#define REG_VCYCLE           0x302040//1057852UL
#define REG_VOFFSET          0x302044//1057856UL
#define REG_VSIZE            0x302048//1057860UL
#define REG_VSYNC0           0x30204C//1057864UL
#define REG_VSYNC1           0x302050//1057868UL
#define REG_DLSWAP           0x302054//1057872UL
#define REG_ROTATE           0x302058//1057876UL
#define REG_OUTBITS          0x30205C//1057880UL
#define REG_DITHER           0x302060//1057884UL
#define REG_SWIZZLE          0x302064//1057888UL
#define REG_CSPREAD          0x302068//1057892UL
#define REG_PCLK_POL         0x30206C//1057896UL
#define REG_PCLK             0x302070//1057900UL

#define REG_CHIPFT           0xC0001
#define REG_ID               0x302000 //1057792UL
#define REG_INT_EN           0x3020AC//1057948UL
#define REG_INT_FLAGS        0x3020A8//1057944UL
#define REG_INT_MASK         0x3020B0//1057952UL
#define REG_MACRO_0          0x3020D8//1057992UL
#define REG_MACRO_1          0x3020DC//1057996UL
#define REG_PLAY             0x30208C//1057928UL
#define REG_PLAYBACK_FORMAT  0x3020C4//1057972UL
#define REG_PLAYBACK_FREQ    0x3020C0//1057968UL
#define REG_PLAYBACK_LENGTH  0x3020B8//1057960UL
#define REG_PLAYBACK_LOOP    0x3020C8//1057976UL
#define REG_PLAYBACK_PLAY    0x3020CC//1057980UL
#define REG_PLAYBACK_READPTR 0x3020BC//1057964UL
#define REG_PLAYBACK_START   0x3020B4//1057956UL
#define REG_PWM_DUTY         0x3020D4//1057988UL
#define REG_PWM_HZ           0x3020D0//1057984UL
#define REG_RENDERMODE       0x302010//1057808UL
#define REG_SNAPSHOT         0x302018//1057816UL
#define REG_SNAPY            0x302014//1057812UL
#define REG_SOUND            0x302088//1057924UL
#define REG_TAG              0x30207C//1057912UL
#define REG_TAG_X            0x302074//1057904UL
#define REG_TAG_Y            0x302078//1057908UL
#define REG_TAP_CRC          0x302024//1057824UL
#define REG_TAP_MASK         0x302028//1057828UL
#define REG_TOUCH_ADC_MODE   3154184UL//1058036UL
#define REG_TOUCH_CHARGE     0x30210C//1058040UL
#define REG_TOUCH_DIRECT_XY  0x30218C//1058164UL
#define REG_TOUCH_DIRECT_Z1Z2 0x302190//1058168UL
#define REG_TOUCH_MODE       0x302104//1058032UL
#define REG_TOUCH_OVERSAMPLE 0x302114//1058048UL
#define REG_TOUCH_RAW_XY     0x30211C//1058056UL
#define REG_TOUCH_RZ         0x302120//1058060UL
#define REG_TOUCH_RZTHRESH   0x302118//1058052UL
#define REG_TOUCH_SCREEN_XY  0x302124//1058064UL
#define REG_TOUCH_SETTLE     0x302110//1058044UL
#define REG_TOUCH_TAG        0x30212C//1058072UL
#define REG_TOUCH_TAG_XY     0x302128//1058068UL
#define REG_TOUCH_TRANSFORM_A 0x302150//1058076UL
#define REG_TOUCH_TRANSFORM_B 0x302154//1058080UL
#define REG_TOUCH_TRANSFORM_C 0x302158//1058084UL
#define REG_TOUCH_TRANSFORM_D 0x30215C//1058088UL
#define REG_TOUCH_TRANSFORM_E 0x302160//1058092UL
#define REG_TOUCH_TRANSFORM_F 0x302164//1058096UL
#define REG_TRIM             0x302180//1058156UL
#define REG_VOL_PB           0x302080//1057916UL
#define REG_VOL_SOUND        0x302084//1057920UL

#define REPEAT               1UL
#define REPLACE              2UL
#define RGB332               4UL
#define RGB565               7UL
#define SRC_ALPHA            2UL
#define TEXT8X8              9UL
#define TEXTVGA              10UL
#define TOUCHMODE_CONTINUOUS 3UL
#define TOUCHMODE_FRAME      2UL
#define TOUCHMODE_OFF        0UL
#define TOUCHMODE_ONESHOT    1UL
#define ULAW_SAMPLES         1UL
#define ZERO                 0UL

#ifdef	__cplusplus
}
#endif

#endif	/* FT_GPU_H */