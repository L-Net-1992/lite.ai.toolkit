//
// Created by DefTruth on 2022/6/20.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../hub/onnx/cv/mobile_human_matting_256x256.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_hair.png";
  std::string save_img_path = "../../../logs/test_lite_mobile_human_matting.jpg";

  lite::cv::matting::MobileHumanMatting *mobile_human_matting =
      new lite::cv::matting::MobileHumanMatting(onnx_path, 4); // 4 threads

  lite::types::MattingContent content;
  cv::Mat img_bgr = cv::imread(test_img_path);
  mobile_human_matting->detect(img_bgr, content, true, true);

  if (content.flag)
  {
    if (!content.pha_mat.empty()) cv::imwrite(save_img_path, content.pha_mat * 255.f);
    std::cout << "Default Version MobileHumanMatting Done!" << std::endl;
  }

  delete mobile_human_matting;
}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../hub/onnx/cv/mobile_human_matting_256x256.onnx";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_hair.png";
  std::string save_img_path = "../../../logs/test_lite_mobile_human_matting_onnx.jpg";

  lite::onnxruntime::cv::matting::MobileHumanMatting *mobile_human_matting =
      new lite::onnxruntime::cv::matting::MobileHumanMatting(onnx_path, 4); // 4 threads

  lite::types::MattingContent content;
  cv::Mat img_bgr = cv::imread(test_img_path);
  mobile_human_matting->detect(img_bgr, content, true, true);

  if (content.flag)
  {
    if (!content.pha_mat.empty()) cv::imwrite(save_img_path, content.pha_mat * 255.f);
    std::cout << "ONNXRuntime Version MobileHumanMatting Done!" << std::endl;
  }

  delete mobile_human_matting;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../hub/mnn/cv/mobile_human_matting_256x256.mnn";
  std::string test_img_path = "../../../examples/lite/resources/test_lite_face_hair.png";
  std::string save_img_path = "../../../logs/test_lite_mobile_human_matting_mnn.jpg";

  lite::mnn::cv::matting::MobileHumanMatting *mobile_human_matting =
      new lite::mnn::cv::matting::MobileHumanMatting(mnn_path, 4); // 4 threads

  lite::types::MattingContent content;
  cv::Mat img_bgr = cv::imread(test_img_path);
  mobile_human_matting->detect(img_bgr, content, true, true);

  if (content.flag)
  {
    if (!content.pha_mat.empty()) cv::imwrite(save_img_path, content.pha_mat * 255.f);
    std::cout << "MNN Version MobileHumanMatting Done!" << std::endl;
  }

  delete mobile_human_matting;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
#endif
}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}
