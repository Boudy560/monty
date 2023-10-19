#include "monty.h"
st_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_f(argv[1]);
	fr_no();
	return (0);
}

/**
 * cr_no - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
st_t *cr_no(int n)
{
	st_t *node;

	node = malloc(sizeof(st_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * fr_no - Frees nodes in the stack.
 */
void fr_no(void)
{
	st_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_qu - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_qu(st_t **new_node, __attribute__((unused))unsigned int ln)
{
	st_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
