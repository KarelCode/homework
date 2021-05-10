#include <stdio.h>

//Functions
int draw_house1 (int width, int height) {
    //Roof
    for (int i = 0; i < ((width - 1) / 2); ++i) {
        for (int j = 0; j < width; ++j) {
            if (j - i == (width-1) / 2 || i + j == (width - 1) / 2) {
                printf("X");
            } else {
                if (j == (width - 1)) {
                    printf(" \n");
                } else {
                    printf(" ");
                }
            }
        }
    }

    //Walls
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1) {
                if (j == width - 1) {
                    printf("X\n");
                } else {
                    printf("X");
                }
            } else {
                if (j == 0 || j == width - 1) {
                    if (j == 0) {
                        printf("X");
                    } else {
                        printf("X\n");
                    }
                } else {
                    printf(" ");
                }
            }
        }
    }


    return 0;
}

int draw_house2 (int width, int height, int fence) {
    //Roof
    for (int i = 0; i < ((width - 1) / 2); ++i) {
        for (int j = 0; j < width; ++j) {
            if (j - i == (width-1) / 2 || i + j == (width - 1) / 2) {
                printf("X");
            } else {
                if (j == (width - 1)) {
                    printf(" \n");
                } else {
                    printf(" ");
                }
            }
        }
    }
    
    //Walls and fence
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width + fence; ++j) {
            if (i < height - fence) {
                if (i == 0) {
                    if (j == width - 1) {
                        printf("X\n");
                        break;
                    } else {
                        printf("X");
                    }
                } else {
                    if (j == 0 || j == width - 1) {
                        if (j == 0) {
                            printf("X");
                        } else {
                            printf("X\n");
                            break;
                        }
                    } else {
                        if (i % 2 == 0) {
                            if (j % 2 == 0) {
                                printf("o");
                            } else {
                                printf("*");
                            }
                        } else {
                            if (j % 2 == 0) {
                                printf("*");
                            } else {
                                printf("o");
                            }
                        }
                    }
                }
            } else {
                if (i == height - 1) {
                    if (j <= width - 1) {
                        printf("X");
                    } else {
                        if (fence % 2 == 0) {
                            if (j % 2 == 0) {
                                if (j == width + fence - 1) {
                                    printf("|\n");
                                } else {
                                    printf("|");
                                }
                            } else {
                                printf("-");
                            }
                        } else {
                            if (j % 2 != 0) {
                                if (j == width + fence - 1) {
                                    printf("|\n");
                                } else{
                                    printf("|");
                                }
                            } else {
                                printf("-");
                            }
                        }
                    }
                } else {
                    if (j < width) {
                        if (j == 0 || j == width - 1) {
                            printf("X");
                        } else {
                            if (i % 2 == 0) {
                                if (j % 2 == 0) {
                                    printf("o");
                                } else {
                                    printf("*");
                                }
                            } else {
                                if (j % 2 == 0) {
                                    printf("*");
                                } else {
                                    printf("o");
                                }
                            }
                        }
                    } else {
                        if (fence % 2 == 0) {
                            if (j == width + fence - 1) {
                                printf("|\n");
                            } else {
                                if (i == height - fence) {
                                    if (j % 2 == 0) {
                                        printf("|");
                                    } else {
                                        printf("-");
                                    }
                                } else {
                                    if (j % 2 == 0) {
                                        printf("|");
                                    } else {
                                        printf(" ");
                                    }
                                }
                            }
                        } else {
                            if (j == width + fence - 1) {
                                printf("|\n");
                            } else {
                                if (i == height - fence) {
                                    if (j % 2 == 0) {
                                        printf("-");
                                    } else {
                                        printf("|");
                                    }
                                } else {
                                    if (j % 2 == 0) {
                                        printf(" ");
                                    } else {
                                        printf("|");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}


int main() {
    // Errors
    int error1 = 100;
    int error2 = 101;
    int error3 = 102;
    int error4 = 103;
    char error_message = 0;

    //Variables
    int width = 0;
    int height = 0;
    int fence = 0;
    int tmp = 0;

    //Input check
    tmp = scanf("%d %d %d", &width, &height, &fence);
    if (tmp >= 2) {
        if (3 <= width && width <= 69 && 3 <= height && height <= 69) {
            if (width % 2 != 0) {
                if (width == height) {
                    if (tmp == 3) {
                        if (fence > 0 && fence < height) {
                            draw_house2(width, height, fence);
                        } else {
                            fprintf(stderr, "Error: Neplatna velikost plotu!\n");
                            error_message = error4;
                        }
                    } else {
                        fprintf(stderr, "Error: Chybny vstup!\n");
                        error_message = error1;
                    }
                } else {
                    draw_house1(width, height);
                }
            } else {
                fprintf(stderr, "Error: Sirka neni liche cislo!\n");
                error_message = error3;
            }
        } else {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            error_message = error2;
        }
    } else {
        fprintf(stderr, "Error: Chybny vstup!\n");
        error_message = error1;
    }


    return error_message;
}
