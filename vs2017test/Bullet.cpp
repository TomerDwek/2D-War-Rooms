#include "Bullet.h"
#include "glut.h"

/* ---------- Constructors ---------- */

Bullet::Bullet()
{
	x = 0;
	y = 0;
	dirx = 1;
	diry = 0;
	isMoving = false;
}

Bullet::Bullet(double bx, double by, bool mv, double dx, double dy)
{
	x = bx;
	y = by;
	isMoving = mv;
	dirx = dx;
	diry = dy;
}

/* ---------- Getters ---------- */

bool Bullet::GetIsMoving()
{
	return isMoving;
}

double Bullet::GetX()
{
	return x;
}

double Bullet::GetY()
{
	return y;
}

/* ---------- Setters ---------- */

void Bullet::SetX(double x)
{
	this->x = x;
}

void Bullet::SetY(double y)
{
	this->y = y;
}

void Bullet::SetDirX(double dx)
{
	dirx = dx;
}

void Bullet::SetDirY(double dy)
{
	diry = dy;
}

void Bullet::StopMoving()
{
	isMoving = false;
}

/* ---------- Game Functions ---------- */

void Bullet::Shoot()
{
	isMoving = true;
}

void Bullet::Move(int maze[MSZ][MSZ])
{
	int row, col;

	if (isMoving)
	{
		row = MSZ * (y + 1) / 2;
		col = MSZ * (x + 1) / 2;

		if (maze[row][col] == WALL) // end of move
		{
			isMoving = false;
		}
		else // go on moving
		{
			x += dirx * SPEED;
			y += diry * SPEED;
		}
	}
}

void Bullet::Draw()
{
	glColor3d(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2d(x, y + 0.01);
	glVertex2d(x + 0.01, y);
	glVertex2d(x , y - 0.01);
	glVertex2d(x - 0.01, y);
	glEnd();
}
