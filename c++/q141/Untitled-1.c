    for ( i = 0; i < size-1; i++)
    {
        int j;
        for ( j = 0; j < size-i-1; j++)
        {
            printf("\nj=%d t== %d %d\n",j, ptr[j].num, ptr[j].freq);
            if (ptr[j].num > ptr[j+1].num) {
                Pair temp;
                // printf("\n j== %d\n", j);
                // printf("\n t== %d %d\n", ptr[j].num, ptr[j].freq);
                temp.num = ptr[j].num;
                temp.freq = ptr[j].freq;

                printf("\n j=%d temp== %d %d, ptr= %d %d\n",j, temp.num, temp.freq, ptr[j].num, ptr[j].freq);

                ptr[j].num = ptr[j+1].num;
                ptr[j].freq = ptr[j+1].freq;

                ptr[j+1].num = temp.num;
                ptr[j+1].freq = temp.freq;

            }
        }
        
    }
