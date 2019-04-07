#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int your_conv( cv::Mat src,
               cv::Mat dst,
               cv::Mat kernel,
               int stride,
               int padding
               )
{
    int src_height = src.rows;
    int src_width = src.cols;

    //int kernel_height = kernel.rows;
    //int kernel_width = kernel.cols;

    //int dst_height = ;
    //int dst_width = ;

    // src.ptr<unsigned char>(i)[ calculate INDEX ]

    // MAKE YOUR OWN CONVOLUTION PROCESS
    int k;//Number of Channel
    int i,j;//i : Width   j : Height



    for(k=0;k<3;k++){
	for (i=0;i<src_width;i=i+stride){
		for (j=0;j<src_height;j=j+stride){
			
		    if(i/=0&&j/=0){
			 dst.at<cv::vec3b>(i,j)[k]=src.at<cv::vec3b>(i-1,j-1)[k]*kernel.at<uchar>(0,0)[k]
				                  +src.at<cv::vec3b>(i-1,j)[k]*kernel.at<uchar>(0,1)[k]
						  +src.at<cv::vec3b>(i-1,j+1)[k]*kernel.at<uchar>(0,2)[k]
						  +src.at<cv::vec3b>(i,j-1)[k]*kernel.at<uchar>(1,0)[k]
						  +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
						  +src.at<cv::vec3b>(i,j+1)[k]*kernel.at<uchar>(1,2)[k]
						  +src.at<cv::vec3b>(i+1,j-1)[k]*kernel.at<uchar>(2,0)[k]
						  +src.at<cv::vec3b>(i+1,j)[k]*kernel.at<uchar>(2,1)[k]
						  +src.at<cv::vec3b>(i+1,j+1)[k]*kernel.at<uchar>(2,2)[k];
		    }
		    else if(i==0 && j==0){
		        //i-1==0 j-1=0
			  dst.at<cv::vec3b>(i,j)[k]=padding*kernel.at<uchar>(0,0)[k]
			                           +padding*kernel.at<uchar>(0,1)[k]
				                   +padding*kernel.at<uchar>(0,2)[k]
				                   +padding*kernel.at<uchar>(1,0)[k]
				                   +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
				                   +src.at<cv::vec3b>(i,j+1)[k]*kernel.at<uchar>(1,2)[k]
				                   +padding*kernel.at<uchar>(2,0)[k]
				                   +src.at<cv::vec3b>(i+1,j)[k]*kernel.at<uchar>(2,1)[k] 	                                                         +src.at<cv::vec3b>(i+1,j+1)[k]*kernel.at<uchar>(2,2)[k];
		    } 
		    else if(i==0){
			//i-1==0
			   dst.at<cv::vec3b>(i,j)[k]=padding*kernel.at<uchar>(0,0)[k]
			                            +padding*kernel.at<uchar>(0,1)[k]
			                            +padding*kernel.at<uchar>(0,2)[k]
			                            +src.at<cv::vec3b>(i,j-1)[k]*kernel.at<uchar>(1,0)[k]
			                            +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
			                            +src.at<cv::vec3b>(i,j+1)[k]*kernel.at<uchar>(1,2)[k]
			                            +src.at<cv::vec3b>(i+1,j-1)[k]*kernel.at<uchar>(2,0)[k]
			                            +src.at<cv::vec3b>(i+1,j)[k]*kernel.at<uchar>(2,1)[k]
			                            +src.at<cv::vec3b>(i+1,j+1)[k]*kernel.at<uchar>(2,2)[k];
			
		    }
		    else if(j==0){
			//j-1==0
		           dst.at<cv::vec3b>(i,j)[k]=padding*kernel.at<uchar>(0,0)[k]
			                            +src.at<cv::vec3b>(i-1,j)[k]*kernel.at<uchar>(0,1)[k]
			                            +src.at<cv::vec3b>(i-1,j+1)[k]*kernel.at<uchar>(0,2)[k]
			                            +padding*kernel.at<uchar>(1,0)[k]
			                            +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
			                            +src.at<cv::vec3b>(i,j+1)[k]*kernel.at<uchar>(1,2)[k]
			                            +padding*kernel.at<uchar>(2,0)[k]
			                            +src.at<cv::vec3b>(i+1,j)[k]*kernel.at<uchar>(2,1)[k]
			                            +src.at<cv::vec3b>(i+1,j+1)[k]*kernel.at<uchar>(2,2)[k];

		    }
		    else if(i==src_width-1&&j==src_height-1){//i+1=0 j+1=0
			   dst.at<cv::vec3b>(i,j)[k]=src.at<cv::vec3b>(i-1,j-1)[k]*kernel.at<uchar>(0,0)[k]
			                            +src.at<cv::vec3b>(i-1,j)[k]*kernel.at<uchar>(0,1)[k]
			                            +padding*kernel.at<uchar>(0,2)[k]
			                            +src.at<cv::vec3b>(i,j-1)[k]*kernel.at<uchar>(1,0)[k]
			                            +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
			                            +padding*kernel.at<uchar>(1,2)[k]
			                            +padding*kernel.at<uchar>(2,0)[k]
			                            +padding*kernel.at<uchar>(2,1)[k]
			                            +padding*kernel.at<uchar>(2,2)[k];
		    }
		    else if(i==src_width-1){//i+1=0
		           dst.at<cv::vec3b>(i,j)[k]=src.at<cv::vec3b>(i-1,j-1)[k]*kernel.at<uchar>(0,0)[k]
			                            +src.at<cv::vec3b>(i-1,j)[k]*kernel.at<uchar>(0,1)[k]
			                            +src.at<cv::vec3b>(i-1,j+1)[k]*kernel.at<uchar>(0,2)[k]
			                            +src.at<cv::vec3b>(i,j-1)[k]*kernel.at<uchar>(1,0)[k]
			                            +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k]
			                            +src.at<cv::vec3b>(i,j+1)[k]*kernel.at<uchar>(1,2)[k]
			                            +padding*kernel.at<uchar>(2,0)[k]
			                            +padding*kernel.at<uchar>(2,1)[k]
			                            +padding*kernel.at<uchar>(2,2)[k];
		    }
		    else {//j+1=0
                         dst.at<cv::vec3b>(i,j)[k]=src.at<cv::vec3b>(i-1,j-1)[k]*kernel.at<uchar>(0,0)[k]
				                  +src.at<cv::vec3b>(i-1,j)[k]*kernel.at<uchar>(0,1)[k]
					          +padding*kernel.at<uchar>(0,2)[k]
					          +src.at<cv::vec3b>(i,j-1)[k]*kernel.at<uchar>(1,0)[k]
					          +src.at<cv::vec3b>(i,j)[k]*kernel.at<uchar>(1,1)[k] 
					          +padding*kernel.at<uchar>(1,2)[k]	
						  +src.at<cv::vec3b>(i+1,j-1)[k]*kernel.at<uchar>(2,0)[k]
						  +src.at<cv::vec3b>(i+1,j)[k]*kernel.at<uchar>(2,1)[k]	
						  +padding*kernel.at<uchar>(2,2)[k];
		    }
		}
	}
    }
	






    // if success
    return 0

    // if fail - in the case of wrong parameters...
    // return -1
}

int main ( int argc, char** argv )
{
    if (argc < 2) {
        std::cout << "no filename given." << std::endl;
        std::cout << "usage: " << argv[0] << " image" << std::endl;
        return -1;
    }

    cv::Mat src, kernel, dst;

    // Load an image
    src = cv::imread( argv[1] );
    if( !src.data )  { return -1; }

    // Make filter (for 3 channels)
    kernel = (cv::Mat_<float>(3, 3, 3) << -1, -1, -1, -1,  8, -1, -1, -1, -1,
                                           0,  0,  0,  0,  0,  0,  0,  0,  0,
                                           0,  0,  0,  0,  0,  0,  0,  0,  0);


    // Run 2D filter
    //cv::filter2D(src, dst, -1 , kernel, cv::Point( -1, -1 ), 0, cv::BORDER_DEFAULT );

    // ---------------------------
    your_conv(src,dst,kernel,1,0);
    // ---------------------------

    cv::namedWindow( "filter2D Demo", cv::WINDOW_AUTOSIZE );
    cv::imshow( "filter2D Demo", dst );

    cv::waitKey(0);
    return 0;
}
