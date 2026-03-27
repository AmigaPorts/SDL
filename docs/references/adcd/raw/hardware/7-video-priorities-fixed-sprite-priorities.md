# 7 / Video Priorities / Fixed Sprite Priorities


You cannot change the relative priorities of the sprites. They will always
appear on the screen with the lower-numbered sprites appearing in front of
(having higher screen priority than) the higher-numbered sprites. This is
shown in Figure 7-1. Each box represents the image of the sprite number
shown in that box.

                                           _______
                                          |       |
                                       ___|___  7 |
                                      |       |___|
                                   ___|___  6 |
                                  |       |___|
                               ___|___  5 |
                              |       |___|
                           ___|___  4 |
                          |       |___|
                       ___|___  3 |
                      |       |___|
                   ___|___  2 |
                  |       |___|
               ___|___  1 |
              |       |___|
              |     0 |
              |_______|


            Figure 7-1: Inter-Sprite Fixed Priorities
