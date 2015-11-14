//$fn=20;
$fn = 50;

module corner() {
	difference() {
		union() {
		minkowski() {
	    cube([7,7,2]);
	    cylinder(r=5,h=30);
		}
		translate([3.5,3.5,0]) cylinder(h=35,r=2.7);
}
		translate([3.5,3.5,0]) cylinder(h=2.3,r=3,$fn=6);
		//translate([3.5,3.5,0]) cylinder(h=35,r=2);
	}
}

rotate([180,0,0]) translate([-30,-30,-30]) difference() { union() {
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

		translate([15,15,57.7]) cylinder(r=2.7, h=6.5);
		translate([15,30,57.7]) cylinder(r=2.7, h=6.5);
		translate([15,45,57.7]) cylinder(r=2.7, h=6.5);
		translate([30,30,57.7]) cylinder(r=2.7, h=6.5);
		translate([45,15,57.7]) cylinder(r=2.7, h=6.5);
		translate([45,30,57.7]) cylinder(r=2.7, h=6.5);
		translate([45,45,57.7]) cylinder(r=2.7, h=6.5);
	}

	translate([1.2,1.2,30]) corner();
	translate([51.8,1.2,30]) corner();
	translate([51.8,51.8,30]) corner();
	translate([1.2,51.8,30]) corner();

	}
translate([4.7,4.7,29.7]) cylinder(h=35,r=2);
translate([55.3,4.7,29.7]) cylinder(h=35,r=2);
translate([4.7,55.3,29.7]) cylinder(h=35,r=2);
translate([55.3,55.3,29.7]) cylinder(h=35,r=2);
}