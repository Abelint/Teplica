// Distance between holes?
hole_distance = 70; // [0:100]
// Offset from center?
hole_offset = 0; // [0:20]





CLIP_H = 6;
CLIP_W = hole_distance;
OFFSET = hole_offset;
CLIP_DENT = 2;
HOLE_DEPTH = 25;
HOLE_DIAMETER = 2.5;

WIDTH = CLIP_W+CLIP_H;
IWIDTH = WIDTH-2*CLIP_H;

module din_clip() {
	difference() {
        union() {
            translate([-7-CLIP_H-CLIP_DENT,OFFSET-max(WIDTH,50)/2,0])
                cube([CLIP_H+CLIP_DENT, max(WIDTH,50), CLIP_H]);
            import("din.stl");
         }
		union() {
			translate([-20, OFFSET-CLIP_W/2, CLIP_H/2]) {
				rotate([0, 90, 0]) {
					cylinder(h= HOLE_DEPTH, r = HOLE_DIAMETER / 2, $fn = 16);
				}
			}
			translate([-20, OFFSET+CLIP_W/2, CLIP_H/2]) {
				rotate([0, 90, 0]) {
					cylinder(h= HOLE_DEPTH, r = HOLE_DIAMETER / 2, $fn = 16);
				}
			}
            translate([-7-2*CLIP_H-CLIP_DENT,OFFSET-IWIDTH/2,0])
                cube([CLIP_H+CLIP_DENT, WIDTH-2*CLIP_H, CLIP_H]);
		}
}

}

din_clip();

