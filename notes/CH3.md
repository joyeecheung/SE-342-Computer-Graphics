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

Which pixels will be displayed.

### Digital Differential Analyzer

### Bresenham
