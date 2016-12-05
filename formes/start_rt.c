/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:03:30 by mmoullec          #+#    #+#             */
/*   Updated: 2016/12/05 15:46:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_formes.h"

double	find_t_det(double a, double b, double c, double det)
{
	double t1;
	double t2;

	t1 = (-b + sqrt(det)) / (2 * a);
	t2 = (-b - sqrt(det)) / (2 * a);
	if (t1 < t2)
		return (t1);
	else
		return (t2);
}

double		min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double		carre(double a)
{
	return (a * a);
}

double	return_a(t_vect r)
{
	double a;

	a = (r.x * r.x) + (r.y * r.y) + (r.z * r.z);
	return (a);
}

double	return_b(t_vect sp, t_vect r, t_vect cam)
{
	double b;
	b = (r.x * (cam.x - sp.x)) + (r.y * (cam.y - sp.y)) + (r.z * (cam.z - sp.z));
	b *= 2;
	return (b);
}

double	return_c(double inter, t_vect sp, t_vect cam)
{
	double c;
	c = carre(cam.x - sp.x) + carre(cam.y - sp.y) + carre(cam.z -sp.z);
	c -= carre(inter);
	return (c);
}

t_rend	to_draw_sphere(t_sphere *s, t_vect cam_origin, t_vect r)
{
	t_rend u;
	double a = return_a(r);
	double b = return_b(s->centre, r, cam_origin);
	double c = return_c(s->rayon, s->centre, cam_origin);
	double det = (b * b) - (4.0 * a * c);
	if (det < 0.0)
	{
		u.imp = 0;
		return (u);
	}
	else
	{
		u.imp = 1;
		u.type = 0;
		if (det == 0.0)
		{
			u.t = (-b / 2*a);
			u.r = s->rgb;
			u.centre = s->centre;
		}
		else
		{
			u.t = min(((-b + sqrt(det)) / 2 * a), ((-b - sqrt(det)) / 2 * a));
			u.r = s->rgb;
			u.centre = s->centre;
		}
		return (u);
	}
}

t_rend	to_draw_plane(t_plan *p, t_vect cam, t_vect r)
{
	t_rend	u;
	double a;
	double b;
	double c;

	u.imp = 1;
	u.type = 1;
	u.r = p->color;
	u.centre = p->pt;
	u.norm = p->norm;
	a = p->norm.x * (cam.x - p->pt.x);
	b = p->norm.y * (cam.y - p->pt.y);
	c = p->norm.z * (cam.z - p->pt.z);

	u.t = -(a + b + c) / (p->norm.x * r.x + p->norm.y * r.y + p->norm.z * r.z);

	return (u);
}

t_rend		ret_tmp(t_list_n *o, t_e *e, t_vect ray)
{
	t_rend tmp;
	if (!ft_strcmp(o->name, "sphere"))
		return (tmp = to_draw_sphere(o->content, e->s->cam_origin, ray));
	else if (!ft_strcmp(o->name, "plan"))
		tmp = to_draw_plane(o->content, e->s->cam_origin, ray);
	return (tmp);
}

void	rend_cpy(t_rend *a, t_rend b)
{
	a->type = b.type;
	a->imp = b.imp;
	a->t = b.t;
	a->r = b.r;
	a->centre = b.centre;
	a->norm = b.norm;
}

void	all_obj(t_e *e, t_list_n **obj, t_l l, t_vect ray)
{
	t_rend	tmp;
	t_list_n *o;
	t_rend		rend;
	o = *obj;

	rend.imp = 0;
	rend.t = -1;
	rend.r = rgb_0();
	while(o)
	{
		tmp = ret_tmp(o, e, ray);
		if (rend.t == -1)
			rend_cpy(&rend, tmp);
		else
		{
			if (tmp.t > rend.t)
				rend_cpy(&rend, tmp);
		}
		o = o->next;
	}
	if (rend.imp == 1)
		gest_lum(e, ray, l, rend);
//	put_color_to_pixel(e->mlx, l, rend.r);
}


int		start_rt(t_e *e)
{
	t_rgb i;
	i.r = 100;
	i.g = 123;
	i.b = 210;
	t_vect vec_dir = find_vect_dir(e->s->cam_origin);
	t_vect up = find_up_vect();
	t_vect ri = find_right_vect();
	t_vect upleft = find_up_left(e->s->cam_origin, up, ri, vec_dir);
	t_vect rayon;
	double xIndent = 1.08 / WW;
	double yIndent = 0.8 / WH;
	t_l l;

	l.x = -1;
	l.y = -1;
	while (++l.y < WH)
	{
		l.x = -1;
		while (++l.x < WW)
		{
			rayon = vect_sub(vect_s_mul(ri, (xIndent * l.x)), vect_s_mul(up, (yIndent * l.y)));
			rayon = vect_add(upleft, rayon);
			rayon = vect_sub(rayon, e->s->cam_origin);
			rayon = vect_unit(rayon);
			all_obj(e, &e->s->obj, l, rayon);
		}
	}
	return (1);
}
