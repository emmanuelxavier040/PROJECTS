#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/input.h>

#define MOUSEFILE "/dev/input/event5"
//

int main(int argc, char *argv[])
{
    int fd;
    struct input_event ie;
    unsigned char *ptr = (unsigned char*)&ie;
    //
    unsigned char button,bLeft,bMiddle,bRight;
    char a,b;                                                            // the relX , relY datas
    int absolute_x,absolute_y;

    if((fd = open(MOUSEFILE, O_RDONLY | O_NONBLOCK )) == -1)
    {
        printf("NonBlocking %s open ERROR\n",MOUSEFILE);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("NonBlocking %s open OK\n",MOUSEFILE);
    }
    

  int sim_fd,simfd1;
  int x, y;
  char buffer[10];

  /* Open the sysfs coordinate node */
  sim_fd = open("/sys/devices/platform/virmouse/vmevent", O_RDWR);
  if (sim_fd < 0) {
    perror("Couldn't open vms coordinate file\n");
    exit(-1);
  }
  while (1) {
   if(read(fd, &ie, sizeof(struct input_event))!=-1)
        {
            //
            button=ptr[0];
            bLeft = button & 0x1;
            bMiddle = ( button & 0x4 ) > 0;
            bRight = ( button & 0x2 ) > 0;
            a=(char) ptr[1];b=(char) ptr[2];
            if(bLeft&bRight) { printf("\nright+left ,EXIT\n");break;}
            // computes absolute x,y coordinates
            absolute_x+=a;
            absolute_y-=b;
            // set absolute reference ?
            if (bRight==1)
            {
                absolute_x=0;
                absolute_y=0;
                printf("Absolute x,y coords origin recorded\n");
            }
            // show it!
            printf("X%i Y%i\n",absolute_x,absolute_y);
            

    /* Convey simulated coordinates to the virtual mouse driver */
    sprintf(buffer, "%d %d %d", absolute_x, absolute_y, 0);
    write(sim_fd, buffer, strlen(buffer));
    fsync(sim_fd);
    sleep(1);
fflush(stdout);
  }
}
	close(fd);
  close(sim_fd);
return 0;
}

		
