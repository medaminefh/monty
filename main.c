#include "main.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(av[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @value: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		p_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = value;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

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
 * push_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 */
void push_to_queue(stack_t **new_node)
{
	stack_t *tmp;

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

/**
 * nop- do nothing
 * @s: stack
 * @l: line number
 */
void nop(__attribute__((unused))stack_t **s, __attribute__((unused))unsigned int l)
{

}
