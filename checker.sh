#!/bin/bash

echo "test1"
ARG="1"; ./push_swap $ARG | ./checker $ARG
ARG="1 2"; ./push_swap $ARG | ./checker $ARG
ARG="2 1"; ./push_swap $ARG | ./checker $ARG
ARG="1 2 3"; ./push_swap $ARG | ./checker $ARG
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
ARG="3 1 2"; ./push_swap $ARG | ./checker $ARG
ARG="1 3 2"; ./push_swap $ARG | ./checker $ARG
ARG="2 3 1"; ./push_swap $ARG | ./checker $ARG

ARG="0 3 2 1"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 1 89 -20"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 1 30 38 90"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 1 30 38 90 300"; ./push_swap $ARG | ./checker $ARG
ARG="3 2 1 30 38 90 300 -20"; ./push_swap $ARG | ./checker $ARG
<<out
out
ARG="3 2 1 30 38 90 -29 -2 10 23 5434 54 56 566 7"; ./push_swap $ARG | ./checker $ARG
ARG="24 34 92 65 77 30 12 32 22 81 64 86 39 90 15 80 23 42 76 43 44 13 96 69 14 53 10 8 60 89 31 48 84 7 55 51 94 40 68 28 36 25 66 100 97 93 3 83 72 21 79 75 1 67 18 99 54 16 95 70 35 49 41 29 46 52 47 56 59 57 17 61 73 20 74 37 38 50 4 26 33 19 6 62 78 5 98 88 63 45 27 11 9 82 71 85 91 87 58 2"; ./push_swap $ARG | ./checker $ARG
ARG="142 376 302 89 68 189 461 353 80 183 84 82 258 421 354 98 483 315 482 473 385 335 499 249 462 269 340 42 282 119 197 174 272 271 99 47 124 125 118 303 424 152 202 96 248 250 210 401 239 412 358 500 333 346 447 35 388 37 76 494 27 34 64 352 284 398 351 471 267 92 246 470 345 67 489 257 316 166 57 193 467 41 414 308 361 312 100 383 94 276 264 160 102 252 226 43 298 154 40 129 339 480 251 83 158 16 24 266 305 486 454 367 30 485 310 29 146 111 380 3 456 452 386 63 55 203 222 336 363 71 127 360 372 327 425 259 318 224 169 435 136 451 369 225 270 17 214 19 297 265 13 418 348 377 390 21 403 426 368 106 70 320 400 157 69 233 402 439 179 260 48 164 384 60 448 73 395 45 497 33 112 221 364 58 468 180 349 444 441 283 396 241 217 104 167 44 105 182 453 18 173 191 458 234 211 438 77 235 133 289 495 370 23 464 109 484 245 25 187 132 278 5 477 355 2 213 72 263 331 397 275 356 95 188 130 291 194 423 26 301 419 199 459 460 196 463 50 366 427 208 247 117 496 172 337 145 285 362 156 32 428 431 101 268 262 334 215 131 328 78 144 87 378 466 237 137 206 449 90 493 230 329 220 445 227 450 330 219 228 165 216 20 14 212 204 149 46 155 287 59 359 36 140 162 205 387 54 309 375 413 408 116 159 139 153 12 341 126 322 446 168 7 389 177 184 56 406 314 86 277 244 242 150 324 121 39 317 53 49 62 175 332 429 163 307 498 6 290 455 350 436 474 161 74 422 218 469 253 79 192 141 279 134 122 11 479 357 280 405 391 437 15 432 299 171 457 81 8 399 342 207 52 374 325 114 115 151 148 123 176 433 22 292 434 143 443 223 319 186 243 38 200 236 9 238 178 478 128 195 147 416 288 487 472 190 381 409 481 91 442 300 1 294 201 256 240 440 410 304 417 491 490 394 65 198 120 420 93 170 343 229 110 475 411 311 231 313 323 103 97 255 488 181 61 306 295 392 382 430 293 28 404 286 296 88 113 415 85 326 66 254 281 261 344 107 465 138 232 75 476 393 492 274 365 135 407 347 108 379 31 10 209 338 185 371 4 273 373 321 51"; ./push_swap $ARG | ./checker $ARG
ARG="24 34 92 65 77 30 12 32 22 81 64 86 39 90 15 80 23 42 76 43 44 13 96 69 14 53 10 8 60 89 31 48 84 7 55 51 94 40 68 28 36 25 66 100 97 93 3 83 72 21 79 75 1 67 18 99 54 16 95 70 35 49 41 29 46 52 47 56 59 57 17 61 73 20 74 37 38 50 4 26 33 19 6 62 78 5 98 88 63 45 27 11 9 82 71 85 91 87 58 2"; ./push_swap $ARG | wc -l
ARG="142 376 302 89 68 189 461 353 80 183 84 82 258 421 354 98 483 315 482 473 385 335 499 249 462 269 340 42 282 119 197 174 272 271 99 47 124 125 118 303 424 152 202 96 248 250 210 401 239 412 358 500 333 346 447 35 388 37 76 494 27 34 64 352 284 398 351 471 267 92 246 470 345 67 489 257 316 166 57 193 467 41 414 308 361 312 100 383 94 276 264 160 102 252 226 43 298 154 40 129 339 480 251 83 158 16 24 266 305 486 454 367 30 485 310 29 146 111 380 3 456 452 386 63 55 203 222 336 363 71 127 360 372 327 425 259 318 224 169 435 136 451 369 225 270 17 214 19 297 265 13 418 348 377 390 21 403 426 368 106 70 320 400 157 69 233 402 439 179 260 48 164 384 60 448 73 395 45 497 33 112 221 364 58 468 180 349 444 441 283 396 241 217 104 167 44 105 182 453 18 173 191 458 234 211 438 77 235 133 289 495 370 23 464 109 484 245 25 187 132 278 5 477 355 2 213 72 263 331 397 275 356 95 188 130 291 194 423 26 301 419 199 459 460 196 463 50 366 427 208 247 117 496 172 337 145 285 362 156 32 428 431 101 268 262 334 215 131 328 78 144 87 378 466 237 137 206 449 90 493 230 329 220 445 227 450 330 219 228 165 216 20 14 212 204 149 46 155 287 59 359 36 140 162 205 387 54 309 375 413 408 116 159 139 153 12 341 126 322 446 168 7 389 177 184 56 406 314 86 277 244 242 150 324 121 39 317 53 49 62 175 332 429 163 307 498 6 290 455 350 436 474 161 74 422 218 469 253 79 192 141 279 134 122 11 479 357 280 405 391 437 15 432 299 171 457 81 8 399 342 207 52 374 325 114 115 151 148 123 176 433 22 292 434 143 443 223 319 186 243 38 200 236 9 238 178 478 128 195 147 416 288 487 472 190 381 409 481 91 442 300 1 294 201 256 240 440 410 304 417 491 490 394 65 198 120 420 93 170 343 229 110 475 411 311 231 313 323 103 97 255 488 181 61 306 295 392 382 430 293 28 404 286 296 88 113 415 85 326 66 254 281 261 344 107 465 138 232 75 476 393 492 274 365 135 407 347 108 379 31 10 209 338 185 371 4 273 373 321 51"; ./push_swap $ARG | wc -l
