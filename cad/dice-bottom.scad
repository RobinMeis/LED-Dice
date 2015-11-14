//$fn=20;
$fn = 50;

module corner() {
  difference() {
    minkowski() {
      cube([7,7,2]);
      cylinder(r=5,h=30);
    }
	
  }
}

module hold() {
	rotate([0,270,0]) union() {
		linear_extrude(height = 16, center = true, convexity = 10, twist = 0)
		polygon(points=[[0,0],[20,0],[0,2]], paths=[[0,1,2]]);
	}
}

rotate([180,0,0]) translate([-30,-30,-30]) union() {
difference() {
union() {
  difference (center=true) {
	
    minkowski() { //Main Cube
      cube([60,60,60]);
      sphere(5);
    }

    translate([-5,-5,-5]) cube([70,70,35]);

    translate([1.2,1.2,-7]) minkowski() { //Inner Cube
      cube([57.6,57.6,60]);
      sphere(5);
    }
}
	translate([1.2,1.2,30]) corner();
  translate([51.8,1.2,30]) corner();
  translate([51.8,51.8,30]) corner();
  translate([1.2,51.8,30]) corner();

	//translate([30,-4,25]) hold();
	//rotate([0,0,90]) translate([30,-64,25]) hold();
	//mirror([0,1,0]) rotate([0,0,-90]) translate([30,-4,25]) hold();
	//mirror([0,1,0]) translate([30,-64,25]) hold();
}
	translate([4.7,4.7,30]) cylinder(h=35,r=2.8);

	translate([4.7,55.3,30]) cylinder(h=35,r=2.8);

	translate([55.3,55.3,30]) cylinder(h=35,r=2.8);

	translate([55.3,4.7,30]) cylinder(h=35,r=2.8);

  }
	difference () {
		translate([4.7,4.7,30]) cylinder(h=3,r=2.8);	
		translate([4.7,4.7,30]) cylinder(h=3,r=1.7);
	}

	difference () {
		translate([4.7,55.3,30]) cylinder(h=3,r=2.8);	
		translate([4.7,55.3,30]) cylinder(h=3,r=1.7);
	}

	difference () {
		translate([55.3,55.3,30]) cylinder(h=3,r=2.8);	
		translate([55.3,55.3,30]) cylinder(h=3,r=1.7);
	}

	difference () {
		translate([55.3,4.7,30]) cylinder(h=3,r=2.8);	
		translate([55.3,4.7,30]) cylinder(h=3,r=1.7);
	}
}
