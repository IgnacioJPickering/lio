#ifndef __EXCHNUM_CONSTANTS_H__
#define __EXCHNUM_CONSTANTS_H__

#define PI 3.141592654f

#define MAX_ATOMS 7 /* era 100 */
#define MAX_NCO 500
#define MAX_CONTRACTIONS 20
// #define MAX_FUNCTIONS (15 * MAX_ATOMS)

// This should correspond to the maximum number in 'layers' and 'layers2'
//#define MAX_LAYERS 50
//#define MAX_LAYERS2 60
#define MAX_LAYERS 60

#define RMM_BLOCK_SIZE_X 8
#define RMM_BLOCK_SIZE_Y 16

#define ENERGY_BLOCK_SIZE_X 1 
#define ENERGY_BLOCK_SIZE_Y 128

#define ENERGY_SHARED_ATOM_POSITIONS 35

const uint cpu_layers[] = {
  30,30,35,35,35,35,35,35,35,35,
  40,40,40,40,40,40,40,40,
  45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
  50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50
};

__device__ __constant__ uint layers[] = {
  30,30,35,35,35,35,35,35,35,35,
	40,40,40,40,40,40,40,40,
  45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,
  50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50
};

const uint cpu_layers2[] = {
	20,20,25,25,25,25,25,25,25,25,
	30,30,30,30,30,30,30,30,
	60,30,30,30,30,30,30,60,
	35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
	40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40
};

__device__ __constant__ uint layers2[] = {
	20,20,25,25,25,25,25,25,25,25,
	30,30,30,30,30,30,30,30,
	60,30,30,30,30,30,30,60,
	35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,
	40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40
};	

__device__ __constant__ float rm_factor[] = {
  /*0.944863438887178,*/ 0.330702203610512, 0.878722998165075, 1.37005198638641,
	0.992106610831537, 0.803133923054101, 0.661404407221024, 0.614161235276665,
	0.566918063332307, 0.472431719443589, 0.670853041609896, 1.70075418999692,
	1.41729515833077, 1.18107929860897, 1.0393497827759, 0.944863438887178,
	0.944863438887178, 0.944863438887178, 0.472431719443589, 3.40150837999384,
	1.41729515833077, 1.18107929860897, 1.0393497827759, 0.944863438887178,
	0.944863438887178, 0.944863438887178, 1.88972687777436, 2.07869956555179,
	1.70075418999692, 1.51178150221948, 1.32280881444205, 1.27556564249769,
	1.32280881444205, 1.32280881444205, 1.32280881444205, 1.27556564249769,
	1.27556564249769, 1.27556564249769, 1.27556564249769, 1.22832247055333,
	1.18107929860897, 1.08659295472025, 1.08659295472025, 1.08659295472025,
	1.08659295472025, 2.22042908138487, 1.88972687777436, 1.70075418999692,
	1.46453833027513, 1.37005198638641, 1.37005198638641, 1.27556564249769,
	1.22832247055333, 1.27556564249769, 1.32280881444205, 1.51178150221948,
	1.46453833027513, 1.46453833027513, 1.37005198638641, 1.37005198638641,
	1.32280881444205, 1.32280881444205, 1.2377711049422
};

/* grid */
__device__ __constant__ float3 small_grid_positions[EXCHNUM_SMALL_GRID_SIZE];
__device__ __constant__ float3 medium_grid_positions[EXCHNUM_MEDIUM_GRID_SIZE];
__device__ __constant__ float3 big_grid_positions[EXCHNUM_BIG_GRID_SIZE];

__device__ __constant__ float small_wang[EXCHNUM_SMALL_GRID_SIZE];
__device__ __constant__ float medium_wang[EXCHNUM_MEDIUM_GRID_SIZE];
__device__ __constant__ float big_wang[EXCHNUM_BIG_GRID_SIZE];

/* pot_kernel constants */
__device__ __constant__ float pot_alpha = -0.738558766382022447;
__device__ __constant__ float pot_gl = 0.620350490899400087;
	
__device__ __constant__ float pot_vosko_a1 = 0.03109205;
__device__ __constant__ float pot_vosko_b1 = 3.72744;
__device__ __constant__ float pot_vosko_c1 = 12.9352;
__device__ __constant__ float pot_vosko_x0 = -0.10498;
__device__ __constant__ float pot_vosko_q = 6.15199066246304849;
__device__ __constant__ float pot_vosko_a16 = 0.005182008333;
__device__ __constant__ float pot_vosko_a2 = 0.015546025;
__device__ __constant__ float pot_vosko_b2 = 7.06042;
__device__ __constant__ float pot_vosko_c2 = 18.0578;
__device__ __constant__ float pot_vosko_x02 = -0.32500;
__device__ __constant__ float pot_vosko_q2 = 4.7309269;
__device__ __constant__ float pot_vosko_a26 = 0.0025910042;

#endif
