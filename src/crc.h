/*
 * crc.h
 * Copyright (C) 2018 pavle <pavle.portic@tilda.center>
 *
 * Distributed under terms of the MIT license.
 */

#pragma once

#include <stddef.h>
#include <stdint.h>

uint8_t crc8(const uint8_t* data, size_t len);

