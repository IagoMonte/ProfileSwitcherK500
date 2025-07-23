#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libusb-1.0/libusb.h>


unsigned char hex_to_byte(const char *hex) {
    unsigned int byte;
    sscanf(hex, "%2x", &byte);
    return (unsigned char)byte;
}

int main(int argc, char **argv) {
    int status;
    int valuer;
    libusb_device_handle *device = NULL;

    int vid = (int)strtol(argv[1],NULL,16);
    int pid = (int)strtol(argv[2],NULL,16);
    unsigned char bmRT = (unsigned char)strtol(argv[3],NULL,16);
    unsigned char bRqst = (unsigned char)strtol(argv[4],NULL,16);
    int wValue = (int)strtol(argv[5],NULL,16);
    int wIndex = (int)strtol(argv[6],NULL,16);
    int timeoutV = 1000;
    const char *filename = argv[7];

    FILE *packagefile = fopen(filename, "r");
    if (!packagefile) {
        perror("Fail open package file");
        return 1;
    }

    fseek(packagefile, 0, SEEK_END);
    long packageSize = ftell(packagefile);
    rewind(packagefile);

    char *hexStr = malloc(packageSize + 1);
    if (!hexStr){
        perror("Memory aloc Fail (packagefile Read)");
        return 1;
    }

    fread(hexStr,1,packageSize,packagefile);
    hexStr[packageSize] = '\0';
    fclose(packagefile);

    char *cleanPackage = malloc(packageSize + 1);
    if (!cleanPackage){
        perror("Memory aloc Fail (CleanPackage)");
        free(hexStr);
        return 1;
    }

    int cleanSize = 0;
    for (int i = 0; hexStr[i] != '\0'; i++) {
        if (hexStr[i] != '\n' && hexStr[i] != '\r' && hexStr[i] != ' ' && hexStr[i] != '\t') {
            cleanPackage[cleanSize++] = hexStr[i];
        }
    }
    cleanPackage[cleanSize] = '\0';
    free(hexStr);

    if (cleanSize % 2 != 0){
        fprintf(stderr, "Error: bytes count error\n");
        free(cleanPackage);
        return 1;
    }

    int dataSize = cleanSize/2;
    unsigned char *data = malloc(dataSize);
    if(!data){
        perror("Memory aloc Fail (data)");
        free(cleanPackage);
        return 1;
    }
    for(int i = 0; i < dataSize; i++){
        data[i] = hex_to_byte(&cleanPackage[i * 2]);
    }
    free(cleanPackage);

    status = libusb_init(NULL);
    if(status != 0){
        perror("Cannot init libusb");
        free(data);
        return -status;
    }

    device = libusb_open_device_with_vid_pid(NULL, vid, pid);
    if(device==NULL){
        printf("Device open Fail\n");
        libusb_exit(NULL);
        free(data);
        return -1;
    }

    if (libusb_kernel_driver_active(device,1)==1){
        libusb_detach_kernel_driver(device,1);
    }

    status = libusb_claim_interface(device,1);
    if (status < 0){
        fprintf(stderr, "Claim Interface Fail: %s\n", libusb_error_name(status));
        libusb_release_interface(device,1);
        libusb_close(device);
        libusb_exit(NULL);
        free(data);
        return -1;
    }

    status = libusb_control_transfer(device,
        bmRT,
        bRqst,
        wValue,
        wIndex,
        data,
        dataSize,
        timeoutV
    );
    if (status < 0){
        fprintf(stderr, "Transfer Fail: %s\n", libusb_error_name(status));
        libusb_release_interface(device,1);
        libusb_close(device);
        libusb_exit(NULL);
        free(data);
        return -1;
    } else {
        printf("Transfer Sucess (%d Transfer Size)\n", status);
    }

    libusb_release_interface(device,1);
    libusb_close(device);
    libusb_exit(NULL);
    free(data);
    return 0;
}