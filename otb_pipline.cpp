//
// Created by auroua on 16-6-14.
//

#include "otbImage.h"
#include "otbImageFileReader.h"
#include "otbImageFileWriter.h"

int main(int argc, char *argv[]) {
    //parameters:    /home/auroua/workspace/data/Examples/QB_Suburb.png /home/auroua/workspace/test333.png
    if (argc != 3)
    {
        std::cerr << "Usage: "
        << argv[0]
        << " <input_filename> <output_filename>"
        << std::endl;
    }
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    //  Declare the image as an \doxygen{otb}{Image}, the pixel type
    // is declared as an unsigned char (one byte) and the image is specified as
    // having two dimensions.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    typedef otb::Image<unsigned char, 2> ImageType;
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    //  To read the image, we need an \doxygen{otb}{ImageFileReader}
    // which is templated with the image type.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    typedef otb::ImageFileReader<ImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    // Then, we need an \doxygen{otb}{ImageFileWriter}
    // also templated with the image type.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    typedef otb::ImageFileWriter<ImageType> WriterType;
    WriterType::Pointer writer = WriterType::New();
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    // The filenames are passed as arguments to the program. We keep it
    // simple for now and we don't check their validity.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    reader->SetFileName(argv[1]);
    writer->SetFileName(argv[2]);
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    // Now that we have all the elements, we connect the pipeline,
    // pluging the output of the reader to the input of the writer.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    writer->SetInput(reader->GetOutput());
    // Software Guide : EndCodeSnippet

    //  Software Guide : BeginLatex
    //
    // And finally, we trigger the pipeline execution calling the Update()
    // method on the last element of the pipeline. The last element will make
    // sure to update all previous elements in the pipeline.
    //
    //  Software Guide : EndLatex

    // Software Guide : BeginCodeSnippet
    writer->Update();

    return EXIT_SUCCESS;
}