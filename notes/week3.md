### Assignments
* Use OpenGL to draw something
* Next one is drawing a circle with the bresenham algorithm

### Details of OpenGL program

* Context
* Viewport
	* By deafault, the entire window
	* Camera
	* Multiple viewports
* State
* Input
	* `glBegin(PRIMITIVE_TYPE)` and `glEnd` surrounding `glVertex{nt}` to specify data
* Color
* `glFlush` is async, `glFinish` is sync

### Transforms

* `glMatrixMode`
* ModelView
	* 3D-3D
	* Model
		* Positioning object
		* Translate, rotate, scale
	* View
		* Positioning camera
		* lookat
	* `glLoadIdentity`, `glLoadMatrix`, `glMulMatrix`
	* Last call is applied first.
* Projection
	* 3D-2D
	* Perspective
		* `glFrustrum`, `gluPerspective`
	* Orthographic
		* `glOrtho`, `glOrtho2D`

### Scan conversion

* Determine which pixels will be displayed.

#### Digital Differential Analyzer
* Use the equation of the line, increment x, round y (use slope)
	* If dy > dx, the line is broken
* Improvement
	* step = max(dx, dy)
	* increment of x = dx/step
	* increment of y = dy/step
	* Round both
* Drawbacks
	* Division
	* Floating numbers
	* Rounding
	* Only y<sub>i</sub> is used to draw y<sub>i+1</sub>

### Bresenham
* Choose min(d<sub>upper</sub>, d<sub>lower</sub>
)
* if p<sub>i</sub> <= 0, draw(x<sub>i</sub> + 1, y<sub>i</sub>) (West)
	* p<sub>i+1</sub> = p<sub>i</sub> + 2dy
* if p<sub>i</sub> > 0, draw(x<sub>i</sub> + 1, y<sub>i</sub> + 1) (Northwest)
	* p<sub>i+1</sub> = p<sub>i</sub> + 2dy - 2dx
