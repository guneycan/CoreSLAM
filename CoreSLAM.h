#ifndef _CoreSLAM_H_
#define _CoreSLAM_H_

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TS_SCAN_SIZE 8192
#define TS_MAP_SIZE 2048
#define TS_MAP_SCALE 0.1
#define TS_DISTANCE_NO_DETECTION 4000
#define TS_NO_OBSTACLE 65500
#define TS_OBSTACLE 0
#define TS_HOLE_WIDTH 600

typedef unsigned short ts_map_pixel_t;

typedef struct
{
	ts_map_pixel_t map[TS_MAP_SIZE * TS_MAP_SIZE];
}ts_map_t;

typedef struct
{
	double x[TS_SCAN_SIZE], y[TS_SCAN_SIZE];
	int value[TS_SCAN_SIZE];
	int nb_points;
}ts_scan_t;

typedef struct
{
	double x, y;	// in mm
	double theta;	// in degrees
}ts_position_t;

void ts_map_init(ts_map_t *map);
int ts_distance_scan_to_map(ts_scan_t *scan, ts_map_t *map, ts_position_t *pos);
void ts_map_update(ts_scan_t *scan, ts_map_t *map, ts_position_t *pos, int quality);

#endif // _CoreSLAM_H_