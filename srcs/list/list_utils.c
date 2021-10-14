/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:38:22 by elaachac          #+#    #+#             */
/*   Updated: 2021/10/14 17:36:45 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*newlist(void)
{
	t_list	*newlist;
	newlist = (t_list *)malloc(sizeof(*newlist));
	if (newlist == NULL)
		return (NULL);
	if (newlist != NULL)
	{
		newlist->lenght = 0;
		newlist->head = NULL;
		newlist->tail = NULL;
	}
	return (newlist);
}

void	dellist(t_list **list)
{
	t_node	*tmp;
	t_node	*del;

	if (list != NULL)
	{
		tmp = (*list)->head;
		while ((*list)->lenght > 0)
		{
			(*list)->lenght--;
			del = tmp;
			if (tmp->next)
				tmp = tmp->next;
			free(del);
		}
		free(*list);
		*list = NULL;
	}
}

void	init_node(t_node *node, int data)
{
	node->data = data;
	node->chunk_pos = -1;
}

t_node	*add_head_list(t_list **list, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	if ((*list) != NULL)
	{
		if ((*list)->tail == NULL)
		{
			(*list)->head = newnode;
			(*list)->tail = newnode;
			newnode->prev = (*list)->tail;
			newnode->next = (*list)->tail;
		}
		else
		{
			(*list)->head->prev = newnode;
			(*list)->tail->next = newnode;
			newnode->next = (*list)->head;
			newnode->prev = (*list)->tail;
			(*list)->head = newnode;
		}
		(*list)->lenght++;
	}
	init_node(newnode, data);
	return (newnode);
}

t_node	*add_tail_list(t_list **list, int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	if ((*list) != NULL)
	{
		if ((*list)->tail == NULL)
		{
			(*list)->head = newnode;
			(*list)->tail = newnode;
			newnode->prev = (*list)->head;
			newnode->next = (*list)->head;
		}
		else
		{
			(*list)->head->prev = newnode;
			(*list)->tail->next = newnode;
			newnode->next = (*list)->head;
			newnode->prev = (*list)->tail;
			(*list)->tail = newnode;
		}
		(*list)->lenght++;
	}
	init_node(newnode, data);
	return (newnode);
}

// "489","241","360","355","219","435","208","123","413","296","283","269","15","119","295","475","270","453","124","99","101","169","353","1","394","49","225","313","180","351","457","100","499","42","90","436","292","294","385","418","40","279","494","10","242","34","446","148","248","188","442","464","268","120","419","45","367","319","299","285","53","140","223","273","431","7","237","192","12","251","327","333","202","33","190","264","377","399","272","488","417","189","330","103","29","30","152","22","337","400","125","393","135","216","85","32","111","480","144","165","274","449","21","35","395","60","469","109","358","398","199","150","481","178","476","338","468","309","252","347","473","410","379","391","497","130","340","282","31","412","460","263","424","115","78","310","374","401","128","259","301","415","26","181","255","18","59","262","478","470","284","490","426","321","193","213","185","91","17","132","227","147","63","131","281","423","364","249","95","9","325","201","434","186","39","298","224","421","127","441","492","93","89","212","217","461","247","484","70","372","276","164","231","66","495","19","98","320","77","61","47","88","406","331","334","112","166","136","363","228","346","253","382","266","207","79","74","233","157","275","343","293","206","389","335","493","260","172","55","153","234","462","336","402","250","41","97","448","381","350","287","405","440","368","141","102","361","432","438","407","138","312","107","28","121","6","114","195","342","289","116","126","420","428","36","203","483","459","396","232","226","451","38","117","267","210","54","161","378","317","143","25","215","486","290","304","46","179","408","83","454","311","314","159","375","467","8","427","409","86","498","445","477","160","84","68","240","348","416","82","87","230","52","96","13","365","455","58","297","291","404","339","139","146","315","198","277","280","158","200","155","390","397","5","491","437","176","370","191","466","458","145","371","236","11","366","288","122","154","69","487","380","349","173","246","323","197","341","167","387","308","261","43","359","156","106","258","37","443","463","465","4","229","271","149","472","75","113","182","50","204","51","345","174","142","256","238","222","27","3","326","450","71","239","500","168","471","344","496","214","474","94","265","433","316","305","384","14","65","456","324","196","56","307","244","76","243","137","386","306","170","24","322","221","108","245","23","81","302","162","373","356","332","425","175","430","177","328","403","183","73","392","452","357","151","92","187","318","369","286","16","303","411","2","439","44","57","482","444","376","254","80","220","205","163","171","485","479","118","134","329","129","278","184","300","133","211","110","388","352","48","72","429","235","105","20","257","422","67","64","209","362","62","194","354","414","218","104","383","447"
// "8", "19", "71", "98", "39", "23", "11", "97", "46", "89", "22", "30", "88", "10", "14", "57", "82", "34", "1", "33", "25", "83", "48", "59", "93", "26", "37", "54", "53", "77", "76", "27", "79", "70", "74", "18", "42", "45", "43", "4", "90", "60", "96", "61", "44", "58", "31", "36", "78", "49", "62", "28", "81", "63", "5", "13", "80", "47", "68", "75", "55", "16", "24", "52", "35", "85", "69", "66", "38", "72", "86", "32", "40", "50", "2", "99", "87", "17", "12", "9", "29", "84", "65", "100", "6", "7", "20", "64", "92", "15", "94", "41", "67", "21", "3", "95", "91", "51", "73", "56"