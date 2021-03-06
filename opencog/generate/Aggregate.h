/*
 * opencog/generate/Aggregate.h
 *
 * Copyright (C) 2020 Linas Vepstas <linasvepstas@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _OPENCOG_AGGREGATE_H
#define _OPENCOG_AGGREGATE_H

#include <set>

#include <opencog/atomspace/AtomSpace.h>
#include <opencog/generate/Frame.h>
#include <opencog/generate/GenerateCallback.h>

namespace opencog
{
/** \addtogroup grp_generate
 *  @{
 */

class Aggregate
{
private:
	AtomSpace* _as;

	/// Decision-maker
	GenerateCallback* _cb;

	/// Current traversal state
	Frame _frame;
	Odometer _odo;

	std::stack<Frame> _frame_stack;
	std::stack<HandleSeq> _odo_sections;
	void push_frame();
	void pop_frame();
	void print_section(const Handle&) const;
	void print_frame(const Frame&) const;

	std::stack<Odometer> _odo_stack;
	void push_odo();
	void pop_odo();

	/// Accumulated set of fully-grounded solutions.
	std::set<HandleSet> _solutions;

	bool init_odometer(void);
	bool step_odometer(void);
	bool do_step(void);
	void print_wheel(size_t) const;
	void print_odometer(void) const;

	bool check_for_solution(void);

	bool recurse(void);

	HandlePair connect_section(const Handle&, const Handle&,
	                           const Handle&, const Handle&);
	Handle make_link(const Handle&, const Handle&,
	                 const Handle&);

public:
	Aggregate(AtomSpace*);
	~Aggregate();

	Handle aggregate(const HandleSet&, GenerateCallback&);

};


/** @}*/
}  // namespace opencog

#endif // _OPENCOG_AGGREGATE_H
