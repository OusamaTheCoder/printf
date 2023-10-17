#include "main.h"

/**
 * init_params - Initializes and resetsthe
 * fields of the parameters struct and buffer.
 * @params: Pointer to the parameters struct to be initialized.
 * @ap: The argument pointer (not used in this function).
 *
 * This function is responsible for resetting
 * the values of the parameters struct
 * and the buffer to their default states. It clears flags,
 * sets default values for
 * width and precision, and resets any modifiers.
 * The argument pointer 'ap' is not used
 * in this function.
 *
 * Return: void
 */
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ap;
}
