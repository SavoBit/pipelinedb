/*-------------------------------------------------------------------------
 *
 * combinerReceiver.h
 *	  An implementation of DestReceiver that that allows combiners to receive
 *	  tuples from worker processes.
 *
 * Copyright (c) 2013-2015, PipelineDB
 *
 * IDENTIFICATION
 *	  src/include/pipeline/combinerReceiver.h
 *
 */
#ifndef COMBINER_RECEIVER_H
#define COMBINER_RECEIVER_H

#include "pipeline/tuplebuf.h"
#include "tcop/dest.h"

extern void *combiner_receiver_peek_fn(void *ptr, int len);
extern void combiner_receiver_pop_fn(void *ptr, int len);
extern void combiner_receiver_copy_fn(void *dest, void *src, int len);

extern DestReceiver *CreateCombinerDestReceiver(void);
extern void SetCombinerDestReceiverParams(DestReceiver *self, TupleBufferBatchReader *reader, Oid cq_id);
extern void SetCombinerDestReceiverHashFunc(DestReceiver *self, FuncExpr *hash, MemoryContext context);

#endif
