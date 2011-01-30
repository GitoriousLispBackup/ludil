#include <ludilBlob.h>
#include <ludilTest.h>

static ludilBlob_t    *g_blob = NULL;
static ludilSize_t     g_size = 3;

DEFTEST(blobInit, "testing if blob initing works")
BEGIN

  ludilBlobInit (&g_blob, g_size);

  ASSERTM ("testing if blob isn't null", (g_blob != NULL));

  ASSERTM ("testing if length matches dataSize", (0 == (g_blob->length)));
  ASSERTM ("testing if size of blob contains the itself", (g_blob->size == (g_size+sizeof (ludilBlob_t))));
  SUCCESS;
END

DEFTEST(blobAdd, "testing if adding data works to blob")
BEGIN
  
  char            v_dummy [1024];
  ludilSize_t     v_check = sizeof (v_dummy);

  g_blob = ludilBlobAdd (g_blob, (ludilPtr_t)v_dummy, sizeof (v_dummy)); 

  ASSERTM ("testing if blob isn't null", (g_blob != NULL));
  ASSERTM ("testing if length matches dataSize", ((v_check == (g_blob->length))));
  ASSERTM ("testing if size of blob contains the itself", (g_blob->size == (v_check+sizeof (ludilBlob_t))));

  SUCCESS;
END


DEFTEST(blobFree, "testing if freeing blob works")
BEGIN
  ludilBlobFree (&g_blob);
  ASSERTM ("testing if we blob is null", (g_blob == NULL));
  SUCCESS;
END

/* test order */
BEGIN_TESTS
  TESTM(blobInit);
  TESTM(blobAdd);
  TESTM(blobFree);
END_TESTS
